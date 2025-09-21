#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, mod = 1e9 + 7;
int n, m;
int w[N], v[N];
int f[N], g[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    g[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            int tmp = max(f[j], f[j - v[i]] + w[i]), cnt = 0;
            if (tmp == f[j]) {
                cnt = (cnt + g[j]) % mod;
            }
            if (tmp == f[j - v[i]] + w[i]) {
                cnt = (cnt + g[j - v[i]]) % mod;
            }
            f[j] = tmp, g[j] = cnt;
        }
    }
    int res = 0;
    for (int i = 0; i <= m; i++) {
        if (f[i] == f[m]) {
            res = (res + g[i]) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}