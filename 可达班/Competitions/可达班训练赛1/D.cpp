#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = INT_MAX / 2;
vector<vector<pair<int, int>>> adj;
unordered_map<int, unordered_map<int, int>> dist;
void floyd_warshall(int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (auto &edge : adj[i]) {
            int v = edge.first;
            int w = edge.second;
            dist[i][v] = min(dist[i][v], w);
            dist[v][i] = min(dist[v][i], w);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i].count(k) == 0) continue;
            for (int j = 1; j <= n; ++j) {
                if (dist[k].count(j) == 0) continue;
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        adj.assign(n + 1, vector<pair<int, int>>());
        dist.clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            int w = pow(2, i + 1);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        floyd_warshall(n);
        int mnLength = INF;
        vector<int> mnE;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (dist[i].count(j) == 0) continue;
                if (dist[i][j] < INF) {
                    for (int k = j + 1; k <= n; ++k) {
                        if (dist[j].count(k) == 0 || dist[k].count(i) == 0) continue;
                        if (dist[j][k] < INF && dist[k][i] < INF) {
                            int length = dist[i][j] + dist[j][k] + dist[k][i];
                            if (length < mnLength) {
                                mnLength = length;
                                mnE.clear();
                                for (int e = 0; e < m; ++e) {
                                    int u = adj[i][e].first;
                                    int v = adj[j][e].first;
                                    if ((u == j && v == k) || (u == k && v == i) || (u == i && v == j)) {
                                        mnE.push_back(e + 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (mnLength == INF) {
            cout << -1 << endl;
        } else {
            sort(mnE.begin(), mnE.end());
            for (int edge : mnE) {
                cout << edge << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
