#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> nums) {
    vector<int> dp(7, INT_MIN);
    dp[0] = 0;
    for (int it : nums) {
        vector<int> dp1 = dp;
        for (int r = 0; r < 7; ++r) {
            if (dp[r] != INT_MIN) {
                int new_r = (r + it) % 7;
                dp1[new_r] = max(dp1[new_r], dp[r] + it);
            }
        }
        dp = dp1;
    }

    return dp[0];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << solve(nums) << '\n';
    return 0;
}
