#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, ans = 0, tmp;
    cin >> n;
    char a[110][110] = {};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= (n + 1) / 2; i++) {
        for(int j = 1; j <= n / 2; j++) {
            tmp = a[i][j] + a[n + 1 - j][i] + a[n + 1 - i][n + 1 - j] + a[j][n + 1 - i] - 4 * '0'; // MD,xssl
            ans += min(tmp, 4 - tmp);
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}