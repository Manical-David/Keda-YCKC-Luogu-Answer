#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b && b == c && c == d) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}