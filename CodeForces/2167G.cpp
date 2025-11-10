// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// constexpr int N = 8010;
// int n;
// int a[N], c[N], s[N], f[N];
// void solve() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 1; i <= n; i++) {
//         cin >> c[i];
//     }
//     for (int i = 1; i <= n; i++) {
//         s[i] = s[i - 1] + c[i];
//     }
//     f[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         f[i] = 1e18;
//         for (int j = 0; j <= i - 1; j++) {
//             if (a[j] <= a[i]) 
//                 f[i] = min(f[i], f[j] + s[i - 1] - s[j]);
//         }
//     }
//     int ans = INT_MAX;
//     for (int i = 1; i <= n; i++) {
//         ans = min(ans, f[i] + s[n] - s[i]);
//     }
//     cout << ans << '\n';
// }
// signed main() {
//     ios::sync_with_stdio(false), cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 8010;
long long t, n, a[N], c[N], dp[N], sum, tmax;
void solve() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sum = 0;
    for (long long i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    tmax = 0;
    for (long long i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += c[i];
        tmax = max(tmax, dp[i]);
    }
    cout << sum - tmax << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}