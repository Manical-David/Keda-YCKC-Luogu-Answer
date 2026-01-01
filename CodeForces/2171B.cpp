#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long first = a[0], last = a[n-1];
    long long ans;
    if (first != -1 && last != -1) {
        ans = llabs(last - first);
    } 
    else {
        ans = 0;
        if (first == -1 && last == -1) {
            a[0] = 0;
            a[n-1] = 0;
        } 
        else if (first == -1) {
            a[0] = last;
        } 
        else { 
            a[n-1] = first;
        }
    }
    for (int i = 0; i < n; ++i) if (a[i] == -1) a[i] = 0;
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
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