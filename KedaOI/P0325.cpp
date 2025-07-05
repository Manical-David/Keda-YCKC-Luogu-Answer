#include <bits/stdc++.h>
using namespace std;
const int N = 501;
vector<int> g[N];
stack<int> path;
int d[N];
int n = 500, m;
void dfs(int u) {
    while (!g[u].empty()) {
        sort(g[u].begin(), g[u].end());
        int v = g[u][0];
        g[u].erase(g[u].begin());
        for (auto it = g[v].begin(); it != g[v].end(); ++it) {
            if (*it == u) {
                g[v].erase(it);
                break;
            }
        }
        dfs(v);
    }
    path.push(u);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    int start = 1;
    int cnt_odd = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 == 1) {
            cnt_odd++;
            if (cnt_odd == 1) {
                start = i;
            }
        }
    }
    if (cnt_odd == 0) {
        for (int i = 1; i <= n; i++) {
            if (d[i] > 0) {
                start = i;
                break;
            }
        }
    }
    dfs(start);
    while (!path.empty()) {
        cout << path.top() << "\n";
        path.pop();
    }
    return 0;
}