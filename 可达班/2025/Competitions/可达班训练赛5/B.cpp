#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false), cin.tie();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 1), ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i - 1] + a[i];
        }
        int m = n - k + 1;
        vector<ll> sum(m+2, LLONG_MIN);
        for (int i = 1; i <= m; i++) {
            sum[i] = ps[i + k - 1] - ps[i - 1];
        }
        vector <ll> l_max(m + 2, LLONG_MIN);
        l_max[1] = sum[1];
        for (int i = 2; i <= m; i++) {
            l_max[i] = max(l_max[i - 1], sum[i]);
        }
        ll ans = LLONG_MIN;
        for (int i = k + 1; i <= m; i++) {
            ans = max(ans, sum[i] + l_max[i - k]);
        }
        cout << ans << "\n";
    }

    return 0;
}
