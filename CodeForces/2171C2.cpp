#include <bits/stdc++.h>
#define int unsigned long long int
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    unsigned long long A = 0, B = 0;
    for (int i = 0; i < n; ++i) A ^= a[i];
    for (int i = 0; i < n; ++i) B ^= b[i];
    if (A == B) {
        cout << "Tie\n";
        return;
    }
    unsigned long long G = A ^ B;
    int p = 63 - __builtin_clzll(G);
    long long pos = -1;
    for (long long i = n - 1; i >= 0; --i) {
        if ( ((a[i] ^ b[i]) >> p) & 1ULL ) { pos = i; break; }
    }
    if (pos % 2 == 0) cout << "Ajisai\n";
    else cout << "Mai\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}