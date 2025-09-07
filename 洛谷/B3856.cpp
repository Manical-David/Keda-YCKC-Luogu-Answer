#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5 + 10;
int t, n;
long long th[N], tf[N];
void solve() {
    long long a, b, c, g, e, f;
    cin >> n >> a >> b >> c >> e >> f >> g;
    long long t1 = (a ? th[a - 1] : 0) + (b ? tf[b - 1] : 0) + c, t2 = (e ? th[e - 1] : 0) + (f ? tf[f - 1] : 0) + g; // sec
    if (t2 < t1) cout << t2 + th[n - 1] - t1 << '\n';
    else cout << t2 - t1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> t;
    th[0] = tf[0] = 1;
    for (int i = 1; i <= 1e5; ++i) tf[i] = tf[i - 1] + (long long)(10 * i + 1);
    for (int i = 1; i <= 1e5; ++i) th[i] = th[i - 1] + tf[i];
    while (t--) {
        solve();
    }
    return 0;
}