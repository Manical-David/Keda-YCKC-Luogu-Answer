#include <bits/stdc++.h>

using namespace std;

constexpr int N = 37, M = 1e3 + 7, mod = 1e9 + 7;

int n, k, target, f[M];

int main() {
    scanf("%d%d%d", &n, &k, &target);

    f[0] = 1;

    // 枚举每一个骰子
    for (int i = 1; i <= n; i++) {
        // 枚举总共的容积
        for (int j = target; j >= 0; j--) {
            /*
                我们原来的f[j]是f[i][j]前面标注了第几维的
                但是当我们优化过后，滚动数组来实现的
                我们第i个骰子一个都不选，会发现f[j]还会有值（之前的值）
                第i个骰子一个不选 - 和题意违背了
            */
            f[j] = 0;
            // 枚举决策
            for (int z = 1; z <= k; z++) {
                if (j >= z) {
                    f[j] += f[j - z];
                    f[j] %= mod;
                }
            }
        }
    }

    printf("%d\n", f[target]);
    return 0;
}