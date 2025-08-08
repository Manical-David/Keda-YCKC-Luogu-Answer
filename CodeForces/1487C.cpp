#include <bits/stdc++.h>
using namespace std;
constexpr int N = 105;
int v[N][N], d[N], r[N][N], c[N];
void solve() {
    memset(v, 0, sizeof(v));
    memset(r, 0, sizeof(r));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int l = 1; l <= n - 1; l++) {
            int k = i;
            bool flag = false;
            memset(c, 0, sizeof(c));
            while (!c[k]) {
                int p = k;
                c[p] = 1;
                k = (k - 1 + l) % n + 1;
                if (v[p][k] || v[k][p] || r[p][k] || r[k][p]) {
                    flag = true;
                    break;
                }
                r[p][k] = r[k][p] = 1;
            }
            k = i;
            memset(c, 0, sizeof(c));
            while (!c[k]) {
                int p = k;
                c[p] = 1;
                k = (k - 1 + l) % n + 1;
                r[p][k] = r[k][p] = 0;
            }
            if (!flag) {
                k = i;
                memset(c, 0, sizeof(c));
                while (!c[k]) {
                    int p = k;
                    c[p] = 1;
                    k = (k - 1 + l) % n + 1;
                    v[p][k] = 1;
                    v[k][p] = -1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cout << v[i][j] << ' ';
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
