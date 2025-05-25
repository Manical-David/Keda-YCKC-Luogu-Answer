// 又来DP了
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    int t;
    cin >> t;
    vector<vector<int>> time_(n + 1, vector<int>(m + 1, N));
    for (int i = 0; i < t; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        time_[x][y] = v;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[1][1] = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int steps = (i - 1) + (j - 1);
            if (time_[i][j] <= steps && !(i == 1 && j == 1))
                continue;
            if (i > 1 && dp[i - 1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
            if (j > 1 && dp[i][j - 1] != -1)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}