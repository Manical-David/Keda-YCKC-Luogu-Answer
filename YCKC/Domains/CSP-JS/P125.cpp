#include <bits/stdc++.h>
using namespace std;
int fx[9] = {0, 2, 1, -2, -1, 2, -2, 1, -1};
int fy[9] = {0, 1, 2, -1, -2, -1, 1, -2, 2};
const int N = 50;
typedef long long ll;
ll f[N][N];
bool s[N][N];
int main() {
    cin.tie();
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n += 2, m += 2, x += 2, y += 2;
    for (int i = 0; i < 9; i++) {
        s[x + fx[i]][y + fy[i]] = true;
    }
    f[2][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (s[i][j])
                continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[n][m];
    return 0;
}