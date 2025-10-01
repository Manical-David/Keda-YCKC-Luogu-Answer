#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    int s_len = n - m;
    if (s_len <= 0) {
        cout << 0 << endl;
        return 0;
    }
    int k_max = n / m;
    vector<int> c0(k_max + 2, 0); // 存储每个k对应的t(i)=0的数量
    vector<int> c1(k_max + 2, 0); // 存储每个k对应的t(i)=1的数量

    // 预处理c0和c1
    for (int k = 1; k <= k_max - 1; ++k) {
        int i_low = (k - 1) * m - 1;
        int i_high = k * m - 1;
        i_high = min(i_high, s_len - 1);
        int start_i = max(0, i_low + 1);
        int end_i = i_high;
        if (start_i > end_i) {
            c0[k] = 0;
            c1[k] = 0;
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        for (int i = start_i; i <= end_i; ++i) {
            int j = i + m;
            int a = (s[i] == '1') ? 1 : 0;
            int b = (s[j] == '1') ? 1 : 0;
            int t = a ^ b;
            if (t == 0) cnt0++;
            else cnt1++;
        }
        c0[k] = cnt0;
        c1[k] = cnt1;
    }

    // 动态规划初始化
    vector<vector<int>> dp(k_max + 2, vector<int>(2, INF));
    dp[1][0] = 0;
    dp[1][1] = 0;

    // 填充DP表
    for (int k = 1; k <= k_max - 1; ++k) {
        for (int v_prev : {0, 1}) {
            if (dp[k][v_prev] == INF) continue;
            for (int v_curr : {0, 1}) {
                int s_k = (v_prev + v_curr) % 2; // 操作2的成本
                int xor_val = v_prev ^ v_curr;
                int op1 = (xor_val == 0) ? c1[k] : c0[k]; // 操作1的成本
                int total = s_k + op1;
                if (dp[k + 1][v_curr] > dp[k][v_prev] + total) {
                    dp[k + 1][v_curr] = dp[k][v_prev] + total;
                }
            }
        }
    }

    // 计算最终结果
    int res0 = dp[k_max][0] + 0;
    int res1 = dp[k_max][1] + 1;
    cout << min(res0, res1) << endl;

    return 0;
}