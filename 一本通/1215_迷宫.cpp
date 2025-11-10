#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int t, n, x, y, x1, tongy, nx, ny, m;
char str;
bool pd, flag[1001][1001];
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !flag[nx][ny]) {
            flag[nx][ny] = true;
            if (nx == x1 && ny == tongy) {
                cout << "YES" << '\n';
                pd = true;
                break;
            }
            else dfs(nx, ny);
        }
    }
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(0);
    cin >> m;
    while(m--) {
        memset(flag, false, sizeof(flag));
        pd = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> str;
                if (str == '#') flag[i][j] = true;
            }
            cin >> x >> y >> x1 >> tongy;
            if (flag[x][y] || flag[x1][tongy]) {
                cout << "NO1\n";
                continue;
            }
            else dfs(x, y);
            if (!pd) cout << "NO2\n";
        }
    }
    return 0;
}