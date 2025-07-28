#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, m, cnt = 0;
vector <int> g[N];
bool st[N];
void dfs(int u) {
    st[u] = true;
    for(int v : g[u]) {
        if(!st[v]) {
            dfs(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt << '\n';
    return 0;
}