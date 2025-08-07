#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 5;
int n, a, b, k, ans, h[N];
signed main() {
    cin >> n >> a >> b >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        h[i] -= 1;
    }
    for (int i = 0; i < n; ++i) {
        h[i] %= a + b;
        h[i] /= a;
    }
    sort(h, h + n);
    for (int i = 0; i < n; ++i) {
        if (h[i] <= k) {
            ans++;
            k -= h[i];
        }
    }
    cout << ans << '\n';
    return 0;
}