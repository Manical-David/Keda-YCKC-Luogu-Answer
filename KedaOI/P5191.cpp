#include <bits/stdc++.h>
using namespace std;
int prof(int k, vector<int>& a) {
    int n = a.size();
    if (n == 0 || k == 0) return 0;
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i-1]) {
                profit += a[i] - a[i-1];
            }
        }
        return profit;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, 0)));
    for (int j = 0; j <= k; ++j) {
        dp[0][j][0] = 0;
        dp[0][j][1] = -a[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + a[i]);
            if (j > 0) {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - a[i]);
            } else {
                dp[i][j][1] = dp[i-1][j][1];
            }
        }
    }

    return dp[n-1][k][0];
}
int main() {
    int N, k;
    cin >> N >> k;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << prof(k, a) << '\n';
    return 0;
}