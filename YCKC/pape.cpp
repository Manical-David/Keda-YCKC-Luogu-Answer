#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, c;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<Edge> edges;
        long long total = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
            edges.push_back({u, v, c});
            if (a[u] != a[v]) {
                total += c;
            }
        }
        while (q--) {
            int v, x;
            cin >> v >> x;
            for (auto [u, c] : adj[v]) {
                if (a[v] != a[u]) {
                    total -= c;
                }
            }
            a[v] = x;
            for (auto [u, c] : adj[v]) {
                if (a[v] != a[u]) {
                    total += c;
                }
            }
            cout << total << '\n';
        }
    }
    return 0;
}
