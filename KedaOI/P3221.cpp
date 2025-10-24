#include <bits/stdc++.h>

using namespace std;

constexpr int N = 27, M = 1e4 + 7;

int n, amount, coin[N], f[N][M];

int main() {
    scanf("%d%d", &n, &amount);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }

    // 求最小值
    memset(f, 0x3f, sizeof(f));

    f[0][0] = 0;
    // 第一位枚举物品
    for (int i = 1; i <= n; i++) {
        // 剩余物品体积
        for (int j = 0; j <= amount; j++) {
            // 剩余物品数量
            for (int k = 0; k * coin[i] <= j; k++) {
                f[i][j] = min(f[i][j], f[i - 1][j - k * coin[i]] + k);
            }
        }
    }

    printf("%d\n", f[n][amount]);
    return 0;
}