#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, a[N], f[N][2];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        f[i][1] = f[i - 1][0] + a[i];
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
    }
    cout << max(f[n][0], f[n][1]) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}