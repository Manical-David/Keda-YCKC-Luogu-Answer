#include <bits/stdc++.h>
using namespace std;
constexpr int N = 27, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};;
char g[N][N];
bool st[N][N];
int n, m;
bool dfs(int x, int y) {
    if(g[x][y] == 'T') return true;
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(st[xx][yy] || g[xx][yy] == '*') continue;
        st[xx][yy] = true;
        if(dfs(xx, yy)) return true;
        st[xx][yy] = false;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int sx = -1, sy = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    if(dfs(sx, sy)) {
        cout << "yes" << '\n';
    }
    else cout << "no" << '\n';
    return 0;
}