#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 7;
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
int f[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d %d", &v[i], &w[i]);
    /*
        1. 枚举物品
            2. 枚举体积
                3. 枚举决策
    */
    for (int i = 1; i <= n; i++) {
        // 0 ~ m:当前体积是从小到大枚举的
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d\n", f[m]);
    return 0;
}