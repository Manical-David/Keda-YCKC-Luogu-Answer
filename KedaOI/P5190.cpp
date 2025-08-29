#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& a) {
    int n = a.size();
    if (n < 2) return 0;
    vector<int> buy1(n, 0);   // 第一次买入
    vector<int> sell1(n, 0);  // 第一次卖出
    vector<int> buy2(n, 0);   // 第二次买入
    vector<int> sell2(n, 0);  // 第二次卖出
    buy1[0] = -a[0];
    sell1[0] = 0;
    buy2[0] = -INT_MAX;
    sell2[0] = 0;
    for (int i = 1; i < n; ++i) {
        buy1[i] = max(buy1[i - 1], -a[i]);
        sell1[i] = max(sell1[i - 1], buy1[i - 1] + a[i]);
        buy2[i] = max(buy2[i - 1], sell1[i - 1] - a[i]);
        sell2[i] = max(sell2[i - 1], buy2[i - 1] + a[i]);
    }
    return sell2[n - 1];
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a) << '\n';
    return 0;
}
