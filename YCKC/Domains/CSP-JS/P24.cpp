#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    bool flag = true;
    long long maxx = 1e18;
    for (int i = n - 1; i >= 0; --i) {
        int ai = a[i];
        long long val1 = ai;
        bool ok1 = (val1 <= maxx);
        long long val2 = -1;
        bool ok2 = false;
        long long thr = maxx + ai;
        auto it = upper_bound(b.begin(), b.end(), thr);
        if (it != b.begin()) {
            --it;
            val2 = *it - ai;
            ok2 = true;
        }
        vector<long long> cnd;
        if (ok1) cnd.push_back(val1);
        if (ok2) cnd.push_back(val2);
        if (cnd.empty()) {
            flag = false;
            break;
        }
        maxx = *max_element(cnd.begin(), cnd.end());
    }
    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}