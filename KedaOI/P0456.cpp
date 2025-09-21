#include <bits/stdc++.h>
using namespace std;
constexpr int N = 37, M = 207;
/*
    w[i]：i这个物品的价值
    v[i]: i这个物品的体积
*/
int w[N], v[N], n, m;
/*
    f[i][j]:
        i：代表有几个物品
        j：代表我们的总体积是多大
*/
int f[N][M];
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &v[i], &w[i]);
    /*
        1. 枚举物品
            2. 枚举体积
                3. 枚举决策
    */
    for (int i = 1; i <= n; i++) {
        // 0 ~ m
        for (int j = 0; j <= m; j++) {
            // 枚举决策：选/不选
            // 1. 不选
            f[i][j] = f[i - 1][j];
            // 2. 选，你当前的容量可以装下第i个物品
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    printf("%d\n", f[n][m]);
    return 0;
}