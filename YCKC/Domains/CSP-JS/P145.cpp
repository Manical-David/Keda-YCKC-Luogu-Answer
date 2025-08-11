#include <bits/stdc++.h>
using namespace std;
void solve() {
    int m, n, ans, f[15][15];
    cin >> m >> n;
    ans = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[0][i] = f[1][i] = 1;
    for (int i = 1; i <= m; i++)
        f[i][1] = 1;
    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
            if (i < j)
                f[i][j] = f[i][i];
            else
                f[i][j] = f[i - j][j] + f[i][j - 1];
    cout << f[m][n] << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}