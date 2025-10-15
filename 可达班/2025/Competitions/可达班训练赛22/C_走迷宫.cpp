#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 200000 + 10;
long long fact[MAX];
long long f[MAX];
long long pow_mod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
void comp() {
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    f[MAX - 1] = pow_mod(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i) {
        f[i] = f[i + 1] * (i + 1) % MOD;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    comp();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 1 && m == 1) {
            printf("1\n");
            continue;
        }
        if (n < 2 || m < 2) {
            printf("0\n");
            continue;
        }
        int a = n + m - 4;
        int b = n - 2;
        if (b < 0 || b > a) {
            printf("0\n");
            continue;
        }
        long long ans = fact[a] * f[b] % MOD;
        ans = ans * f[a - b] % MOD;
        printf("%lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}