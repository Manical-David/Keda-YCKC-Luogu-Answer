#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool solve() {
    int n;
    ll H;
    if (!(cin >> n >> H)) return false;
    ll prev = 0;
    ll low = H, high = H;
    for (int i = 0; i < n; ++i) {
        ll t, l, u;
        cin >> t >> l >> u;
        ll dt = t - prev;
        low = max(1LL, low - dt);
        high = high + dt;
        if (low > u || high < l) {
            cout << "No\n";
            for (int j = i + 1; j < n; ++j) {
                ll tt, llv, uu; cin >> tt >> llv >> uu;
            }
            return true;
        }
        low = max(low, l);
        high = min(high, u);
        prev = t;
    }
    cout << "Yes\n";
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}