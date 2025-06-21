#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> p, sz;
    vector<ll> edges;
    DSU(int n): p(n + 1), sz(n + 1, 1), edges(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            edges[a]++;
            return;
        }
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        edges[a] += edges[b] + 1;
    }
};
int main(){
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int u, v, z;
        cin >> u >> v >> z;
        dsu.unite(u, v);
    }
    ll ans = 0;
    vector <bool> vis(n + 1, false);
    for(int i = 1; i <= n; i++) {
        int root = dsu.find(i);
        if(!vis[root]) {
            vis[root] = true;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}