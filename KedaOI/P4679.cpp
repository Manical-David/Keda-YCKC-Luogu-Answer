#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 3; l <= n; ++l) {
        for (int i = 0; i + l - 1 < n; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                int rec = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
                if (rec < dp[i][j]) {
                    dp[i][j] = rec;
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}