#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, M1 = 27, M2 = 87;
int n, m, t;
int v1[N], v2[N], w[N];
int f[N][M1][M2];
int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &v1[i], &v2[i], &w[i]);
    }
    // 求最小值 --- 一开始需要初始化为最大值
    memset(f, 0x3f, sizeof(f));
    // 把所有j，k小于0的情况都合并到f[0][0][0]进行转移
    for (int i = 0; i <= t; i++) {
        f[i][0][0] = 0;
    }
    /*
        1. 枚举物品
        2. 枚举体积
            体积可能不止一个，即有体积又有重量
        3. 枚举决策
    */
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m; k++) {
                f[i][j][k] =
                    min(f[i - 1][j][k],
                        f[i - 1][max(0, j - v1[i])][max(0, k - v2[i])] + w[i]);
            }
        }
    }
    printf("%d\n", f[t][n][m]);
    return 0;
}