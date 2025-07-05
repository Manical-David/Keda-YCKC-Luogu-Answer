#include <bits/stdc++.h>
using namespace std;
const int MOO = 80112002;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            dp[v] = (dp[v] + dp[u]) % MOO;
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (outdeg[i] == 0) {
            ans = (ans + dp[i]) % MOO;
        }
    }
    cout << ans << endl;
    return 0;
}