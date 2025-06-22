// 豁出去了，直接用DP写
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<int> pows;
    for (int i = 1; ; ++i) {
        int t = i * i * i * i;
        if (t > m) break;
        pows.push_back(t);
    }
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int p : pows) {
            if (i >= p && dp[i - p] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - p] + 1);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}