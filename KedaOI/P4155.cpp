#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> art(n);
    for (int i = 0; i < n; i++) {
        cin >> art[i];
    }
    // 滑动窗口
    unordered_map<int, int> ans; // 记录窗口内每个名师的出现次数
    int cnt = 0;          // 当前窗口内不同名师的数量
    int l = 0, r = 0;       // 滑动窗口的左右边界
    int ml = INT_MAX;      // 最小区间长度
    int ans_l = 0, ans_r = 0; // 最优区间的左右边界
    while (r < n) {
        // 扩展右边界
        if (ans[art[r]] == 0) {
            cnt++;
        }
        ans[art[r]]++;
        r++;
        // 收缩左边界，直到窗口内不再包含所有名师
        while (cnt == m) {
            if (r - l < ml) {
                ml = r - l;
                ans_l = l;
                ans_r = r - 1;
            }
            ans[art[l]]--;
            if (ans[art[l]] == 0) {
                cnt--;
            }
            l++;
        }
    }
    cout << ans_l + 1 << " " << ans_r + 1 << endl;
    return 0;
}