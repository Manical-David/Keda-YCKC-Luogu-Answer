#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5 + 10;
int n, a[N], f[N][3][2];
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j <= 2; j++) {
        f[1][j][0] = 0;
        f[1][j][1] = -a[1];
    }
    memset(f, -0x3f3f, sizeof f);
    f[1][0][0] = 0, f[1][0][1] = -a[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            f[i][j][0] = f[i - 1][j][0];
            if(j >= 1) {
                f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + a[i]);
            }
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - a[i]);
        }
    } 
    cout << max({f[n][0][0], f[n][1][0], f[n][2][0]}) << '\n';
    return 0;
}