#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char g[N][N];
bool st[N][N];

// 从(x, y)可以走到哪些数字点
void dfs(int x, int y) {
    // 现在已经走到了(x, y)
    st[x][y] = true;
    // 递归的分裂条件：上下左右
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        // 1. 合法性检验
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        // 2. 合理性检验
        if (st[xx][yy] || g[xx][yy] == '0') continue;
        dfs(xx, yy);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    int res = 0;
    // 分别以每一个还没有被标记的点作为起点去标记其他人形成一个细胞块
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '0' && st[i][j] == false) {
                // 说明我们找到了一个新的细胞块
                res += 1;
                // 把当前可以标记的所有数字点都标记上
                dfs(i, j);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}