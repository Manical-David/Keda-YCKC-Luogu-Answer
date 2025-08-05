#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    int r = 0, l;
    bool f = false;
    while (n--) {
        cin >> l;
        if (l - r >= s) f = true;
        cin >> r;
    }
    if (m - r >= s) f = true;
    if (f) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}