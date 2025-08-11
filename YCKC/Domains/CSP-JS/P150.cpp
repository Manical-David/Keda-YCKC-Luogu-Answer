#include <bits/stdc++.h>
using namespace std;
constexpr int N = 57, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, g[N][N];
bool st[N][N];
void dfs(int x, int y) {
    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx < 0 || xx > n + 1 || yy < 0 || yy > n + 1) continue;
        if (st[xx][yy]) continue;
        dfs(xx, yy);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            st[i][j] = g[i][j];
        }
    }
    dfs(0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j] == false) {
                printf("2 ");
            } else {
                printf("%d ", g[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}