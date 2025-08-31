#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    int maxx = nums[0];
    int minn = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
        int tmp_maxx = maxx;
        int tmp_minn = minn;
        maxx = max({nums[i], tmp_maxx * nums[i], tmp_minn * nums[i]});
        minn = min({nums[i], tmp_maxx * nums[i], tmp_minn * nums[i]});
        ans = max(ans, maxx);
    }
    
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << solve(nums) << '\n';
    return 0;
}