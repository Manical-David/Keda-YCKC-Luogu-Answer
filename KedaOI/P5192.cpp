#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& a, int fee) {
    int n = a.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -a[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + a[i] - fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - a[i]);
    }

    return dp[n-1][0];
}
int main() {
    int N, fee;
    cin >> N >> fee;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << solve(a, fee) << '\n';
    return 0;
}
