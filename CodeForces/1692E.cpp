#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int a[N];
void solve() {
    int n, s;
    cin >> n >> s;
    int l = 1, r = 1;
    int ans = 0x3fffffff;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    if (sum < s) {
        cout << -1 << '\n';
        return;
    }
    sum = a[1];
    while (l <= n && r <= n) {
        if (sum == s) {
            ans = min(l - 1 + n - r, ans);
            r++;
            sum += a[r];
        }
        else if (sum > s) {
            sum -= a[l];
            l++;
        }
        else {
            r++;
            sum += a[r];
        }
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
