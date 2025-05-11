#include <bits/stdc++.h>

using namespace std;

constexpr int N = 57, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, g[N][N];
bool st[N][N];

// 用(x, y)覆盖(x, y)可以覆盖的点
void dfs(int x, int y) {
    st[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        // 1. 合法性检验:认为补充了一圈[0, n + 1]
        if (xx < 0 || xx > n + 1 || yy < 0 || yy > n + 1) continue;
        // 2. 合理性检验:
        if (st[xx][yy]) continue;
        // 让(xx, yy)点把他可以覆盖的点覆盖
        dfs(xx, yy);
    }
}

int main() {
    scanf("%d", &n);
    // 要人为的在最外圈填上一层0
    // 输入的时候直接从1开始输入即可
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            // 把一开始1的位置直接标记为已经走过
            st[i][j] = g[i][j];
        }
    }
    // 这里不需要人为填充了，没有填的点默认就是0
    // 从我们认为设定的(0, 0)模拟洪水爆发，看看可以覆盖哪些点
    dfs(0, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j] == false) {
                // 未被洪水覆盖
                printf("2 ");
            } else {
                printf("%d ", g[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}