#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int x[N], ls[N], f[N], l[N];
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        ls[i] = mp[x[i]];
        mp[x[i]] = i;
    }
    int ans = 0, pos;
    for (int i = 1; i <= n; ++i) {
        if (f[ls[i]] - (i - ls[i] - 1) > 0) {
            f[i] = f[ls[i]] - (i - ls[i] - 1) + 1;
            l[i] = l[ls[i]];
        }
        else {
            f[i] = 1;
            l[i] = i;
        }
        if (f[i] > ans) {
            ans = f[i];
            pos = i;
        }
    }
    cout << x[pos] << ' ' << l[pos] << ' ' << pos << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}