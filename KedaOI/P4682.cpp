#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int ans;
    cin >> s >> ans;
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            dp[i][i][0] = 1;
            dp[i][i][1] = 0;
        } else if (s[i] == '1') {
            dp[i][i][0] = 0;
            dp[i][i][1] = 1;
        }
    }
    for (int len = 3; len <= n; len += 2) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k += 2) {
                char op = s[k];
                int l = dp[i][k - 1][0];
                int l1 = dp[i][k - 1][1];
                int r = dp[k + 1][j][0];
                int r1 = dp[k + 1][j][1];
                if (op == '&') {
                    dp[i][j][1] += l1 * r1;
                    dp[i][j][0] += l * r + l * r1 + l1 * r;
                } else if (op == '|') {
                    dp[i][j][1] += l1 * r + l * r1 + l1 * r1;
                    dp[i][j][0] += l * r;
                } else if (op == '^') {
                    dp[i][j][1] += l1 * r + l * r1;
                    dp[i][j][0] += l * r + l1 * r1;
                }
            }
        }
    }
    cout << dp[0][n - 1][ans] << '\n';
    return 0;
}