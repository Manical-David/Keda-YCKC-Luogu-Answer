#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int x = 2; x <= 200; x++) {
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (__gcd(x, a[i]) == 1) {
                cout << x << '\n';
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t-- ) {
        solve();
    }
    return 0;
}