#include <bits/stdc++.h>
using namespace std;
constexpr int N = 107, mod = 1e9 + 7;
int n, m, k;
int a[N], b[N], f[N][N];
int main() {
    // ios::sync_with_stdio(false), cin.tie(0);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);

    for (int i = 0; i <= m; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= b[i]; j--) {
            for (int z = 0; z <= k; z++) {
                    f[j][z] = (f[j][z] + f[j - b[i]][max(z - a[i], 0)]) % mod;
            }
        }
    }
    printf("%d\n", f[m][k]);
    return 0;
}