#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, a[N], f[N][2];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0][0] = 0, f[0][1] = INT_MIN / 2;
    for(int i = 1; i <= n; i++) {
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i]);
    }
    cout << f[n][0] << '\n';
    return 0;
}