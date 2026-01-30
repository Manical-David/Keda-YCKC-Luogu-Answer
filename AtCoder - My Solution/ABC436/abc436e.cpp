#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<char> vis(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int cur = i, len = 0;
        while (!vis[cur]) {
            vis[cur] = 1;
            ++len;
            cur = p[cur];
        }
        ans += 1ll * len * (len - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}