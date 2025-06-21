#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
    vector<int> p, sz;
    vector<ll> edgeCnt;
    DSU(int n): p(n+1), sz(n+1,1), edgeCnt(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    void unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            edgeCnt[ru]++;
            return;
        }
        if (sz[ru] < sz[rv]) swap(ru, rv);
        p[rv] = ru;
        sz[ru] += sz[rv];
        edgeCnt[ru] += edgeCnt[rv] + 1;
    }
};
int main(){
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    vector<bool> seen(n+1,false);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int r = dsu.find(i);
        if (seen[r]) continue;
        seen[r] = true;
        ll s = dsu.sz[r];
        ll have = dsu.edgeCnt[r];
        ll need = s * (s - 1LL) / 2LL - have;
        ans += need;
    }
    cout << ans << "\n";
    return 0;
}