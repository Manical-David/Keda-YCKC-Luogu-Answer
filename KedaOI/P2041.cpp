#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int min_dist = INT_MAX;
    int min_sum = 0;
    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            int dist = abs(sum - target);
            if (dist < min_dist || (dist == min_dist && sum < min_sum)) {
                min_dist = dist;
                min_sum = sum;
            }
            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
    }
    cout << min_dist << " " << min_sum << endl;
    return 0;
}