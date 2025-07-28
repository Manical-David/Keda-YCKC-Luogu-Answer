#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
vector <int> g[N];
int tim[N], sz[N], a[N], diff[N];
int time_stamp = 0;
void dfs(int u, int fa) {
    tim[u] = ++time_stamp;
    sz[u] = 1;
    for(int v : g[u]) {
        if(v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    } 
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while(q--) {
        int u, x;
        cin >> u >> x;
        diff[tim[u]] += x;
        diff[tim[u] + sz[u]] -= x;
    }
    for(int i = 1; i <= time_stamp; i++) {
        diff[i] += diff[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        a[i] += diff[tim[i]];
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}