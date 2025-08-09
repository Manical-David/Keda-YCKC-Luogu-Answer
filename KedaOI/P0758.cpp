#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int grid[N][N];
int dp[N * 2][N][N];
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int k = 2; k <= m + n; ++k) {
        for (int i1 = 1; i1 <= m; ++i1) {
            for (int i2 = 1; i2 <= m; ++i2) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 < 1 || j1 > n || j2 < 1 || j2 > n) continue;
                int num = grid[i1][j1];
                if (i1 != i2 || j1 != j2) num += grid[i2][j2];
                int maxx = 0;
                if (i1 > 1 && i2 > 1) maxx = max(maxx, dp[k - 1][i1 - 1][i2 - 1]);
                if (i1 > 1 && j2 > 1) maxx = max(maxx, dp[k - 1][i1 - 1][i2]);
                if (j1 > 1 && i2 > 1) maxx = max(maxx, dp[k - 1][i1][i2 - 1]);
                if (j1 > 1 && j2 > 1) maxx = max(maxx, dp[k - 1][i1][i2]);
                dp[k][i1][i2] = maxx + num;
            }
        }
    }

    cout << dp[m + n][m][m] << endl;
    return 0;
}
