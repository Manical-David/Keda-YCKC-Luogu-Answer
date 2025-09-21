#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, M = 1e2 + 7;
int n, m1, m2;
int f[M][M];
int main() {
    scanf("%d%d%d", &n, &m1, &m2);
    // 枚举物品
    for (int i = 1; i <= n; i++) {
        int w1, w2, v;
        scanf("%d%d%d", &w1, &w2, &v);
        // 枚举体积
        for (int j1 = m1; j1 >= w1; j1--) {
            // 枚举重量
            for (int j2 = m2; j2 >= w2; j2--) {
                f[j1][j2] = max(f[j1][j2], f[j1 - w1][j2 - w2] + v);
            }
        }
    }
    printf("%d\n", f[m1][m2]);
    return 0;
}