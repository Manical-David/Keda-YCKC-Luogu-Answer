#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(-1e9);
    a.push_back(1e9);
    n += 2;
    sort(a.begin(), a.end());
    int l = 0, r = x;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        int f = 0;
        a[0] = -mid;
        a[n - 1] = x + mid;
        for (int i = 1; i < n; i++) {
            f += max(0, a[i] - 2 * mid - a[i - 1] + 1);
        }
        if (f >= k) l = mid;
        else r = mid - 1;
    }
    a[0] = -l;
    a[n - 1] = x + l;
    int j = 0;
    for (int i = 1; i < n; i++) {
        j = max(j, a[i - 1] + l);
        while(j <= min(a[i] - l, x) && k) {
            cout << j << ' ';
            j++;
            k--;
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t-- ){
        solve();
    }
    return 0;
}