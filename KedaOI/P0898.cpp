#include <bits/stdc++.h>
using namespace std;
int robLinear(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[n - 1];
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (n == 1) {
        cout << nums[0] << '\n';
        return 0;
    }
    vector<int> nums1(nums.begin() + 1, nums.end());
    vector<int> nums2(nums.begin(), nums.end() - 1);
    int result = max(robLinear(nums1), robLinear(nums2));
    cout << result << '\n';

    return 0;
}
/*
题目描述
现有一名专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。影响他偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定n个房间和一个代表每个房屋存放金额的非负整数数组，要你计算在不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

输入格式
输入的第一行为一个整数 
n
n (
≤
500
≤500)，代表房屋个数 接下来一行为 
n
n 个整数，代表每个房屋存放的金额

输出格式
输出一个整数，为该小偷一夜之内能够偷窃到的最高金额

输入数据 1
3
2 3 2
输出数据 1
3
输入数据 2
4
1 2 3 1
输出数据 2
4
提示
样例1说明：

不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。因此只有2号房屋

样例2说明：

先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。 偷窃到的最高金额 = 1 + 3 = 4 。
*/