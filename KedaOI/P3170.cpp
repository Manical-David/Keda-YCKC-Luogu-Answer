#include <bits/stdc++.h>
using namespace std;
constexpr int N = 107, M = 1e6 + 7, mod = 1e9 + 7;
int n, k, a[N], f[M][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= a[i]; j--) {
            for (int len = 1; len <= i; len++) {
                f[j][len] = (f[j][len] + f[j - a[i]][len - 1]) % mod;
            }
        }
    }
    int res = 0, mi2 = 1;
    for (int i = n; i >= 0; i--) {
        res = (res + 1ll * f[k][i] * mi2 % mod) % mod;
        mi2 = 1ll * mi2 * 2 % mod;
    }
    cout << res << '\n';
    return 0;
}