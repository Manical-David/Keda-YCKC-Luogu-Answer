#include <bits/stdc++.h>
using namespace std;
constexpr int N = 107;
int a[N][N], f[N][N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) {
                f[i][j] = a[i][j];
            }
            else {
                if(i > 1) {
                    f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
                }
                if(j > 1) {
                    f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
                }
            }
        }
    }
    cout << f[n][n] << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}