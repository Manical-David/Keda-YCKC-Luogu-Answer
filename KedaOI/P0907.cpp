#include  <bits/stdc++.h>
using namespace std;
int solve(vector<int>& b, vector<int>& add, int n, int m) {
    sort(add.begin(), add.end()); // 对供暖器位置进行排序
    int res = 0; // 最小加热半径初始化为0
    for (int i = 0; i < n; i++) {
        int pos = b[i];
        // 使用二分查找找到离当前房屋最近的供暖器
        auto it = lower_bound(add.begin(), add.end(), pos);
        int l1 = (it != add.end()) ? abs(*it - pos) : INT_MAX; // 距离右侧供暖器的距离
        int r1 = (it != add.begin()) ? abs(*(it - 1) - pos) : INT_MAX; // 距离左侧供暖器的距离
        res = max(res, min(l1, r1)); // 更新最小加热半径
    }
    return res; // 返回最小加热半径
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n), add(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> add[i];
    cout << solve(b, add, n, m) << endl;
    return 0;
}