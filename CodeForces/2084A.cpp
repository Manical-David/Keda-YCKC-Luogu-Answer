#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return ;
    }
    cout << n << ' ';
    for (int i = 1; i < n; i++) {
        cout << i << ' ';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}