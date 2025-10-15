#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    ll n, x, d;
    cin >> n >> x >> d;

    if (d == 0) {
        if (x == 0) {
            cout << 1 << '\n';
        } else {
            cout << n + 1 << '\n';
        }
        return 0;
    }
    ll ans = 0;
    for (ll k = 0; k <= n; ++k) {
        ans += k * (n - k) + 1;
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
