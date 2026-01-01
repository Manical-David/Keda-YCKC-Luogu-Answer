#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> spf(n + 1);
    for (int i = 0; i <= n; ++i) spf[i] = 0;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j <= n; j += i) if (spf[j] == 0) spf[j] = i;
        }
    }
    vector <vector<int> > tongs(n + 1);
    for (int i = 2; i <= n; ++i) tongs[spf[i]].push_back(i);
    vector<int> ans;
    ans.reserve(n);
    for (int p = 2; p <= n; ++p) {
        for (int x : tongs[p]) ans.push_back(x);
    }
    if (n >= 1) ans.push_back(1);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}