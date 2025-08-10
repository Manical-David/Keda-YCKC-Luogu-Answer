#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 100010, nn = 35;
int t, n, k;
int a[N][nn];
int dp[N][nn];
void solve() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= 31; ++j)
            dp[i][j] = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%intd", &a[i][0]);
        for (int j = 1; j <= 31; ++j)
            a[i][j] = a[i][j - 1] / 2;
    }
    int ans = -1e18;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 31; ++j) {
            dp[i][j] = dp[i - 1][j] + a[i][j] - k;
            if (j >= 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]); // 今天刚学
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}
signed main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}