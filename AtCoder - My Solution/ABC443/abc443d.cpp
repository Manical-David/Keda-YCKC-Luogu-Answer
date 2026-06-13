#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i];
    }
    vector<int> l(n), r(n);
    l[0] = R[0];
    for (int i = 1; i < n; ++i) {
        l[i] = min(R[i], l[i - 1] + 1);
    }
    r[n - 1] = R[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        r[i] = min(R[i], r[i + 1] + 1);
    }
    vector<int> pos_f(n);
    for (int i = 0; i < n; ++i) {
        pos_f[i] = min(l[i], r[i]);
    }
    long long ops = 0;
    for (int i = 0; i < n; ++i) {
        ops += R[i] - pos_f[i];
    }
    cout << ops << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}