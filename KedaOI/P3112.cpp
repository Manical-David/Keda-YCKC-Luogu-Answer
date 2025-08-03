#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, m, f[N][N];
char a[N], b[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> a + 1 >> m >> b + 1;
    for(int i = 0; i <= m; i++) {
        f[0][i] = i;
    }
    for(int i = 0; i <= n; i++) {
        f[i][0] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = min({
                f[i - 1][j] + 1,
                f[i][j - 1] + 1,
                f[i - 1][j - 1] + (a[i] != b[j])
            });
        }
    }
    cout << f[n][m] << '\n';
    return 0;
}