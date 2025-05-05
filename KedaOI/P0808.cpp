#include <bits/stdc++.h>
using namespace std;
constexpr int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
constexpr int N = 107;
int n, m, h[N][N];
int dfs(int x, int y) {
    int res = 1;
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if(h[x][y] <= h[xx][yy]) continue;
        res = max(res, dfs(xx, yy) + 1);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> h[i][j];
        }
    }
    int res = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            res = max(res, dfs(i, j));
        }
    }
    cout << res << '\n';
    return 0;
}