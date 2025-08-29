#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 2e5 + 10;
int a[N], b[N], ff[N], fg[N];
int fnd(int x, int f[]) {
    if (f[x] == x)
        return x;
    return f[x] = fnd(f[x], f);
}
void ini(int x, int y, int f[]) {
    int rx = fnd(x, f), ry = fnd(y, f);
    if (rx != ry)
        f[rx] = ry;
    return;
}
void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        ff[i] = fg[i] = i;
    }
    for (int i = 1; i <= m1; i++) {
        cin >> a[i] >> b[i];
    }
    while (m2--) {
        int u, v;
        cin >> u >> v;
        ini(u, v, fg);
    }
    int delcnt = 0;
    for (int i = 1; i <= m1; i++) {
        if (fnd(a[i], fg) == fnd(b[i], fg)) {
            ini(a[i], b[i], ff);
        }
        else
            delcnt++;
    }
    int cntf = 0, cntg = 0;
    for (int i = 1; i <= n; i++) {
        if (ff[i] == i)
            cntf++;
        if (fg[i] == i)
            cntg++;
    }
    cout << cntf - cntg + delcnt << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
