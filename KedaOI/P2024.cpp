#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct Edge {
    int to, cost;
};
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int p, q, t;
        cin >> p >> q >> t;
        g[p].push_back({q, t});
    }
    int w;
    cin >> w;
    vector<int> starts(w);
    for (int i = 0; i < w; ++i) cin >> starts[i];
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int st : starts) {
        dist[st] = 0;
        pq.push({0, st});
    }
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : g[u]) {
            if (dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    if (dist[s] == INF) cout << -1 << endl;
    else cout << dist[s] << endl;
    return 0;
}