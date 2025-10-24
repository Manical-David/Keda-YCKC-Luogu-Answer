#include <bits/stdc++.h>
using namespace std;
constexpr int N = 37, M = 207;
int v[N], w[N];
int f[N][M];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << "max=" << f[n][m];
    return 0;
}