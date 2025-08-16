#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    map<int, int> to;
    to.clear(); // no clear, clear bear.┭┮﹏┭┮
    int n, k;
    cin >> n >> k;
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        to[x[i]]++;
    }
    int ans = 0;
    for (auto it : to) {
        int x = it.first, y = it.second;
        if (!y)
            continue;
        if (k - x == x) {
            ans += y / 2;
        }
        else {
            if (to[k - x] > 0) {
                int sub = min(to[k - x], to[x]);
                ans += sub;
                to[k - x] -= sub;
                to[x] -= sub;
            }
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}