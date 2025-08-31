#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct Edge {
    int to, rev, cap, cost;
};

class MinCostFlow {
public:
    int n;
    vector<vector<Edge>> g;
    vector<int> h, dist, prevv, preve;

    MinCostFlow(int n): n(n), g(n), h(n), dist(n), prevv(n), preve(n) {}

    void add(int from, int to, int cap, int cost) {
        g[from].push_back({to, (int)g[to].size(), cap, cost});
        g[to].push_back({from, (int)g[from].size()-1, 0, -cost});
    }

    int flow(int s, int t, int f) {
        int res = 0;
        fill(h.begin(), h.end(), 0);
        while (f > 0) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [d, v] = pq.top(); pq.pop();
                if (dist[v] < d) continue;
                for (int i = 0; i < g[v].size(); ++i) {
                    Edge &e = g[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
            if (dist[t] == INF) return -1;
            for (int v = 0; v < n; ++v) h[v] += dist[v];
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    vector<pair<int,int>> ops(M);
    for (int i = 0; i < M; ++i) cin >> ops[i].first >> ops[i].second;

    // 统计每个点需要的提升
    vector<int> need(N+1, 0);
    int total_need = 0;
    for (int i = 2; i <= N; ++i) {
        if (A[i-1] > A[i]) {
            need[i] = A[i-1] - A[i];
            total_need += need[i];
        }
    }

    // 建图
    // S: 0, O_j: 1~M, P_i: M+1~M+N, T: M+N+1
    int S = 0, T = M+N+1;
    MinCostFlow mcf(M+N+2);

    // S -> O_j
    for (int j = 0; j < M; ++j) {
        mcf.add(S, 1+j, INF, 1);
    }
    // O_j -> P_i
    for (int j = 0; j < M; ++j) {
        for (int i = ops[j].first; i <= ops[j].second; ++i) {
            mcf.add(1+j, M+i, INF, 0);
        }
    }
    // P_i -> T
    for (int i = 2; i <= N; ++i) {
        if (need[i] > 0)
            mcf.add(M+i, T, need[i], 0);
    }

    int res = mcf.flow(S, T, total_need);
    cout << res << endl;
    return 0;
}