#include <bits/stdc++.h>
using namespace std;
constexpr int N = 107, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char g[N][N];
bool st[N][N];
void dfs(int x, int y) {
    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (st[xx][yy] || g[xx][yy] == '0') continue;
        dfs(xx, yy);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '0' && st[i][j] == false) {
                res += 1;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}