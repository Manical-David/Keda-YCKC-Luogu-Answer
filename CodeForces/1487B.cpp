#include <bits/stdc++.h>
using namespace std;
int t, n, k, p;
void solve() {
    cin >> n >> k;
    if (!(n & 1)) {
        p = (k - 1) % n + 1;
    }
    else {
        p = ((k - 1) + ((k - 1) / (n >> 1))) % n + 1;
    }
    cout << p << '\n';
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