#include <bits/stdc++.h>
using namespace std;
int fnd(vector<int>& nums) {
    int cur = nums[0];
    int maxx = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        cur = max(nums[i], cur + nums[i]);
        maxx = max(maxx, cur);
    }
    return maxx;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << fnd(nums) << endl;
    return 0;
}