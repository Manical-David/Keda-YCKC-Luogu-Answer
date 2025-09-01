#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7, K = 107;
int n, m, w[N];
int f[N][K][2];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    memset(f, -0x3f, sizeof(f));
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = max(f[i - 1][j][1] + w[i], f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j - 1][0] - w[i], f[i - 1][j][1]);
        }
    }
    int res = 0;
    for(int j = 0; j <= m; j++) {
        res = max(res, f[n][j][0]);
    }
    cout << res << '\n';
    return 0;
} // 以开仓为一次交易分界线