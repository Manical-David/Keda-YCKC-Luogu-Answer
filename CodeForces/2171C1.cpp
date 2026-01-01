#include <bits/stdc++.h> // Powered my SJC
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int xr = 0;
    for (int i = 0; i < n; ++i) xr ^= (a[i] ^ b[i]);
    if (xr == 0) {
        cout << "Tie\n";
        return;
    }
    int ls = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            ls = i + 1;
            break;
        }
    }
    if (ls % 2 == 1) cout << "Ajisai\n";
    else cout << "Mai\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}