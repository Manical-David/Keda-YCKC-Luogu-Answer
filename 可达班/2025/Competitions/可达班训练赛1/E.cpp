#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    // dp[i][j]：处理到前i位，余数为j的方案数
    // cnt[i][j]：处理到前i位，余数为j，且至少有一个后缀模k为0的方案数
    vector<vector<int>> dp(n + 1, vector<int>(k, 0));
    vector<vector<int>> cnt(n + 1, vector<int>(k, 0));
    dp[0][0] = 1; // 初始状态：空数字的余数为0
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp[i - 1][j] == 0) continue;
            for (int d = (i == 1 ? 1 : 0); d <= 9; ++d) { // 第一位不能为0
                int new_j = (j * 10 + d) % k;
                dp[i][new_j] = (dp[i][new_j] + dp[i - 1][j]) % m;
                if (new_j == 0) {
                    cnt[i][new_j] = (cnt[i][new_j] + dp[i - 1][j]) % m;
                } else {
                    cnt[i][new_j] = (cnt[i][new_j] + cnt[i - 1][j]) % m;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < k; ++j) {
        ans = (ans + cnt[n][j]) % m;
    }
    cout << ans << endl;
    return 0;
}