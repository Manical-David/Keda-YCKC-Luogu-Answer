#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        auto it = lower_bound(nums.begin(), nums.end(), num);
        int minn;
        if (it == nums.begin()) {
            minn = *it - num;
        } else if (it == nums.end()) {
            minn = num - *(it - 1);
        } else {
            int diff1 = num - *(it - 1);
            int diff2 = *it - num;
            minn = min(diff1, diff2);
        }
        ans += minn;
    }
    cout << ans << endl;
    return 0;
}