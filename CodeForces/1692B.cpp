// CF1692B All Distinct
#include <bits/stdc++.h>
#define int long long
#define elif else if
using namespace std;
int a[10010];
void solve() {
    memset(a, 0, sizeof(a));
    int n, x, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (!a[x])
            ++ans, ++a[x];
    }
    if (ans % 2 == n % 2)
        cout << ans << "\n";
    else
        cout << ans - 1 << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        solve();
    return 0;
}
