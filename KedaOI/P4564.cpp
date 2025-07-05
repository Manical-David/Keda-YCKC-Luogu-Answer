#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; ++i) indeg[g[i]]++;
    vector<int> maxx(n, 1);
    queue<int> q;
    vector<bool> st(n, true);
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        st[u] = false;
        int v = g[u];
        if (--indeg[v] == 0) q.push(v);
        maxx[v] = max(maxx[v], maxx[u] + 1);
    }
    int ans = 0, pSum = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) {
        if (st[i] && !vis[i]) {
            int len = 0, u = i;
            do {
                vis[u] = true;
                u = g[u];
                len++;
            } while (u != i);
            if (len == 2) {
                int a = i, b = g[i];
                pSum += maxx[a] + maxx[b];
            } else {
                ans = max(ans, len);
            }
        }
    }
    ans = max(ans, pSum);
    cout << ans << endl;
    return 0;
}