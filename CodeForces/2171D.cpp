#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector <int> prem(n + 1, INT_MAX), sumf(n + 2, INT_MIN);
    for (int i = 1; i <= n; ++i)
        prem[i] = min(prem[i - 1], pos[i]);
    for (int i = n; i >= 1; --i)
        sumf[i] = max(sumf[i + 1], pos[i]);
    bool ok = true;
    for (int k = 1; k < n; ++k) {
        if (prem[k] > sumf[k + 1]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
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