#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct Edge {
    int to;
    ll cost;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll val;
        cin >> u >> v >> val;
        g[u].push_back({v, val});
        g[v].push_back({u, val});
    }
    // dijkstra
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1] = w[1];
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : g[u]) {
            ll nd = d + e.cost + w[e.to];
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}