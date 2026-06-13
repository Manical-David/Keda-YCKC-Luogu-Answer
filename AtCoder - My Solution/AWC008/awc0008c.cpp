#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long pre = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        pre += a[i];
    }
    int ans = 0;
    if (pre <= 0) ans++;
    for (int i = k; i < n; i++) {
        cin >> a[i];
        pre = pre - a[i - k] + a[i];
        if (pre <= 0) ans++;
    }
    cout << ans << '\n';
    return 0;
}