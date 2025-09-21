#include <bits/stdc++.h>
using namespace std;
constexpr int N = 27, M = 1e3 + 7;
int n, m;
int f[M];
int main() {
    scanf("%d%d", &n, &m);
    // 因为我们是恰好为多少的体积：初始化f数组
    // 从前i个物品中进行选择，且总体积为0的方案数 = 1，一个都不选
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        scanf("%d", &v);

        for (int j = m; j >= v; j--) {
            f[j] += f[j - v];
        }
    }
    // 从前n个物品进行选择且总体积恰好为m的方案数
    printf("%d\n", f[m]);
    return 0;
}