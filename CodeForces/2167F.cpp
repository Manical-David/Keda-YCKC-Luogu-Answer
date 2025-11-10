#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 2e5 + 10;
int n, k;
int f[N], sz[N], deg[N];
int h[N], e[2 * N], ne[2 * N], idx;
ll ans;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs1(int u, int fa) {
    f[u] = deg[u] = 0;
    sz[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        dfs1(j, u);
        f[u] += f[j];
        sz[u] += sz[j];
        deg[u]++;
    }
    if (sz[u] >= k) f[u]++;
}
void dfs2(int u, int fa) {
    ans += f[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == fa)continue;
        if (sz[u] >= k) f[u]--;
        f[u] -= f[j];
        sz[u] -= sz[j];
        deg[u]--;
        if (sz[u] >= k) f[u] ++;
        if (sz[j] >= k) f[j]--;
        f[j] += f[u];
        sz[j] += sz[u];
        deg[j]++;
        if (sz[j] >= k) f[j]++;
        dfs2(j, u);
        if (sz[j] >= k) f[j]--;
        f[j] -= f[u];
        sz[j] -= sz[u];
        deg[j]--;
        if(sz[j] >= k) f[j]++;
        if(sz[u] >= k) f[u]--;
        f[u] += f[j];
        sz[u] += sz[j];
        deg[u]++;
        if(sz[u] >= k) f[u]++;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        idx = 0;
        for (int i = 1; i <= n; i++) h[i] = -1;
        for (int i = 1; i <= n - 1; i++) {
            int a, b;
            cin >> a >> b;
            add(a, b);
            add(b, a);
        }
        dfs1(1, -1);
        ans = 0;
        dfs2(1, -1);
        cout << ans << '\n';
    }
    return 0;
}