#include <bits/stdc++.h>
using namespace std;
constexpr int N = 117;
constexpr int dir[8][2] = {
    {0, 1},  
    {0, -1},  
    {-1, 0}, 
    {1, 0},
    {-1, 1}, 
    {-1, -1}, 
    {1, 1},  
    {1, -1}
};
int n, m, res = 0;
char g[N][N];
void dfs(int x, int y) {\
    g[x][y] = '.';
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int xx = x + i, yy = y + j;
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (g[xx][yy] != 'W') continue;
            dfs(xx, yy);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W') {
                dfs(i, j);
                res += 1;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}