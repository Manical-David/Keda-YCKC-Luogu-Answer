#include <bits/stdc++.h>
using namespace std;
void solve() {
    vector <int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(), a.end());
    int ans = -0x3f3f3f;
    for (int i = 0; i <= n - 1; i += 2) {
        ans = max(a[i + 1] - a[i], ans);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}