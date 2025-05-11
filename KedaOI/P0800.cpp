#include <bits/stdc++.h>
using namespace std;
constexpr int N = 7;
constexpr int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m, t, sx, sy, ex, ey;
int res = 0;
int g[N][N], st[N][N];
void dfs(int x, int y) {
    // stop expression
    if(x == ex && y == ey) {
        res += 1;
        return ;
    }
    // 分裂条件
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if(g[xx][yy] == 1 || st[xx][yy]) continue;
        st[xx][yy] = true;
        dfs(xx, yy);
        st[xx][yy] = false;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m >> t;
    cin >> sx >> sy >> ex >> ey;
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    st[sx][sy] = true;
    dfs(sx, sy);
    cout << res << '\n';
    return 0;
}