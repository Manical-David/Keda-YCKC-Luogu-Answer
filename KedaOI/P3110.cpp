#include <bits/stdc++.h>
using namespace std;
int solve(int k, vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || k == 0) return 0;
    if (k >= n / 2) {
        int pro = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                pro += nums[i] - nums[i-1];
            }
        }
        return pro;
    }
    vector<vector<int>> dp(k + 1, vector<int>(2, 0));
    for (int j = 0; j <= k; ++j) {
        dp[j][0] = 0;
        dp[j][1] = -nums[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[j][0] = max(dp[j][0], dp[j][1] + nums[i]);
            dp[j][1] = max(dp[j][1], dp[j-1][0] - nums[i]);
        }
    }
    return dp[k][0];
}
int main() {
    int N, k;
    cin >> N >> k;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cout << solve(k, a) << endl;
    return 0;
}
