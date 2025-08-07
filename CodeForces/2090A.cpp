#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll x, y, a;
    cin >> x >> y >> a;
    if(a % (x + y) < x) {
        cout << "NO\n";
    }
    else cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}