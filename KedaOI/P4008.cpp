#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char mp[N][N];
bool vis[N][N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool dfs(int x, int y, int bx, int by, char color) {
    vis[x][y] = true;

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (mp[nx][ny] != color) continue;

        if (!vis[nx][ny]) {
            if (dfs(nx, ny, x, y, color)) return true;
        } else if (nx != bx || ny != by) {
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> mp[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j])
                if (dfs(i, j, -1, -1, mp[i][j])) {
                    cout << "Yes" << endl;
                    return 0;
                }
    cout << "No" << endl;
    return 0;
}