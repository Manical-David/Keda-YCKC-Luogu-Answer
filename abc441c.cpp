#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (int m = 1; m <= n; ++m) {
        int t = max(0, m - (n - k));
        long long oa = 0;
        if (t > 0) oa = pref[m] - pref[m - t];
        if (oa >= x) {
            cout << m << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}