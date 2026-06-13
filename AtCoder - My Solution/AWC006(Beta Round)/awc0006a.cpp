#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, l, w;
    cin >> n >> l >> w;
    vector <int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int lmin = l - w, lmax = l + w, ans = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] >= lmin && d[i] <= lmax) ans++;
    }
    cout << ans;
    return 0;
}