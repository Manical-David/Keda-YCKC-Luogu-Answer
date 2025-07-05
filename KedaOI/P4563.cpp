#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> time(n + 1);
    for (int i = 1; i <= n; ++i) cin >> time[i];
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) {
            dp[i] = time[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + time[v]);
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}