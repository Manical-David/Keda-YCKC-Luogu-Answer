#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    int ans = 0, y = 0, x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            y += x;
            x = a[i];
        }
        else y += a[i];
        if (y == x) ans++;
    }
    cout << ans << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}