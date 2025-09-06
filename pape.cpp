#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, K = 1e2 + 1;
int f[N][K][3];
int w[N];
int n, k;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            f[i][j][0] = f[i - 1][j][0];
            f[i][j][0] = max(f[i][j][0], f[i - 1][j][2] - w[i]);
            f[i][j][0] = max(f[i][j][0], f[i - 1][j][1] + w[i]);
            f[i][j][1] = f[i - 1][j][1];
            if(j >= 1) {
                f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][0] - w[i]);
            }
            f[i][j][2] = f[i - 1][j][2];
            if(j >= 1) {
                f[i][j][2] = max(f[i][j][2], f[i - 1][j - 1][0] + w[i]);
            }
        }
    }
    int maxx = 0;
    for(int j = 0; j <= k; j++) {
        maxx = max(maxx, f[n][j][0]);
    }
    cout << maxx << '\n';
    return 0;
}