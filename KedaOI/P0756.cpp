#include <bits/stdc++.h>
using namespace std;
constexpr int N = 17;
int n, a[N][N],f[N * 2][N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    int x, y, val;
    while(cin >> x >> y >> val) {
        if(x == 0 && y == 0 && val == 0) break;
        a[x][y] = val;
    }
    for(int k = 2; k <= n + n; k++) {
        for(int i1 = 1; i1 <= n; i1++) {
            for(int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if(j1 < 1 || j1 > n || j2 < 1 || j2 > n) continue;
                int t = a[i1][j1];
                if(i1 != i2) t += a[i2][j2];
                f[k][i1][i2] = max({
                    f[k][i1][i2] + t,
                    f[k - 1][i1 - 1][i2 - 1] + t,
                    f[k - 1][i1 - 1][i2] + t,
                    f[k - 1][i1][i2 - 1] + t,
                    f[k - 1][i1][i2] + t
                });
            }
        }
    }
    cout << f[n + n][n][n] << '\n';
    return 0;
}