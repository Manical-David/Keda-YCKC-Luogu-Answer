#include <bits/stdc++.h>
using namespace std;
constexpr int N_MAX = 10;
char a[2][N_MAX][N_MAX];
bool vis[2][N_MAX][N_MAX];
int n, m, t;
bool flag;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int z, int x, int y, int cnt) {
    if (flag) return;
    if (cnt > t) return;
    if (a[z][x][y] == 'P') {
        flag = true;
        return;
    }
    if (a[z][x][y] == '#') {
        int dz = 1 - z;
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (a[dz][x][y] != '*' && !vis[dz][x][y]) {
                vis[dz][x][y] = true;
                dfs(dz, x, y, cnt);
                vis[dz][x][y] = false;
            }
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        int dz = z;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
            if (a[dz][dx][dy] != '*' && !vis[dz][dx][dy]) {
                vis[dz][dx][dy] = true;
                dfs(dz, dx, dy, cnt + 1);
                vis[dz][dx][dy] = false;
            }
        }
    }
}
void solve() {
    memset(vis, false, sizeof(vis));
    flag = false;
    for (int z = 0; z < 2; ++z) {
        for (int x = 0; x < n; ++x) {
            cin >> a[z][x];
        }
    }
    vis[0][0][0] = true;
    dfs(0, 0, 0, 0);
    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m >> t;
        solve();
    }
    return 0;
}