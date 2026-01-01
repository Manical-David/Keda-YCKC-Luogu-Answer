#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e18;
struct edge {
    int to;
    int val;
};
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector <vector <edge> > g(n + 1);
    for (int i = 0; i <m; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        g[u].push_back({v, val});
        g[v].push_back({u, val});
    }
    // dijkstra
    vector <int> dist(n + 1, MAXN);
    priority_queue <pair <int, int>, vector <pair <int, int > >, greater < > > pq;
    dist[1] = w[1];
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : g[u]) {
            int nd = d + e.val + w[e.to];
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    for (int i = 2; i <= n; i++) { // because we need to except the edge of the beginnning of the gragh out. （鸡爪英语）
        cout << dist[i] << ' ';
    }
    puts("");
    return 0;
}