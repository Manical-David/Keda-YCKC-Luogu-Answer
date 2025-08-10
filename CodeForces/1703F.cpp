#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e5 + 10;
int a[N], sum[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) sum[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < i) sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
        if (a[i] > 0 && a[i] < i) ans += sum[a[i] - 1];
    }
    cout << ans << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}