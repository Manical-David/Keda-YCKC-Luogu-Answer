#include <bits/stdc++.h>
using namespace std;
void flip(vector<string>& g, int x, int y, int n, int m) {
    g[x][y] =                     (g[x][y] == 'X') ? '.' : 'X';
    if (x > 0)      g[x - 1][y] = (g[x - 1][y] == 'X') ? '.' : 'X';
    if (x < n - 1)  g[x + 1][y] = (g[x + 1][y] == 'X') ? '.' : 'X'; 
    if (y > 0)      g[x][y - 1] = (g[x][y - 1] == 'X') ? '.' : 'X';
    if (y < m - 1)  g[x][y + 1] = (g[x][y + 1] == 'X') ? '.' : 'X';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("flip.in", "r", stdin);
    freopen("flip.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int minn = INT_MAX;
    for (int i = 0; i < (1 << m); ++i) {
        vector<string> g = a;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                flip(g, 0, j, n, m);
                cnt++;
            }
        }
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (g[j-1][k] == 'X') {
                    flip(g, j, k, n, m);
                    cnt++;
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            if (g[n-1][j] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            minn = min(minn, cnt);
        }
    }
    cout << minn << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}