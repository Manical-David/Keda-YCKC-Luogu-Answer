#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n;
vector<int> a, b, c;
vector<vector<int>> g;
ll ans = 0;
pair<int, int> dfs(int u, int fa, int min_a) {
    int cnt01 = 0, cnt10 = 0;
    if (b[u] != c[u]) {
        if (b[u] == 0) cnt01++;
        else cnt10++;
    }
    for (int v : g[u]) {
        if (v == fa) continue;
        auto [x, y] = dfs(v, u, min(min_a, a[u]));
        cnt01 += x;
        cnt10 += y;
    }
    int t = min(cnt01, cnt10);
    ans += 1LL * t * a[u];
    cnt01 -= t;
    cnt10 -= t;
    return {cnt01, cnt10};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    a.resize(n); b.resize(n); c.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
    g.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto [cnt01, cnt10] = dfs(0, -1, a[0]);
    if (cnt01 || cnt10) cout << -1 << '\n';
    else cout << ans * 2 << '\n';
    return 0;
}
