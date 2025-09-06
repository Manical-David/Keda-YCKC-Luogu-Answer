#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, a[N];
char str[N];
long long dp[N][3][3];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> (str + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][0][(str[1] - '0')] = 0;
    dp[1][0][(str[1] - '0') ^ 1] = a[1];
    for(int i = 2; i <= n; i++) {
        int t = str[i] - '0';
        for(int k = 0; k < 3; k++) {
            dp[i][0][k] = dp[i - 1][0][k ^ 1] + (k == t ? 0 : a[i]);
            dp[i][1][k] = min(dp[i - 1][1][k ^ 1], dp[i - 1][0][k]) + (k == t ? 0 : a[i]);
        }
    }
    cout << min(dp[n][1][0], dp[n][1][1]) << '\n';
    return 0;
}