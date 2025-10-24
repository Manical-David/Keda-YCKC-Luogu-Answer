#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, m, t;
int w[N], v[N], f[N];
int idx[N];
int a[N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> m >> n >> t;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        a[p][++idx[p]] = i;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= idx[i]; k++) {
                int x = a[i][k];
                if (j >= v[x]) {
                    f[j] = max(f[j], f[j - v[x]] + w[x]);
                }
            }
        }
    }
    cout << f[m];
    return 0;
}