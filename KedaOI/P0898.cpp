#include <bits/stdc++.h>
using namespace std;
constexpr int N = 507;
int n, a[N], f[N][2];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        f[i][1] = f[i - 1][0] + a[i];
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
    }
    int ans1 = max(f[n - 1][0], f[n - 1][1]);
    memset(f, 0, sizeof f);
    for(int i = 2; i <= n; i++) {
        f[i][1] = f[i - 1][0] + a[i];
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
    }
    int ans2 = max(f[n][0], f[n][1]);
    cout << max(ans1, ans2) << '\n';
    return 0;
}