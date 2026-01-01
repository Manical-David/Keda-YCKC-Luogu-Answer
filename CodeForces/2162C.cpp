#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    unsigned int ua = static_cast<unsigned int>(a);
    unsigned int bw = ua == 0u ? 0u : (32u - __builtin_clz(ua));
    ua = static_cast<unsigned int>(((1ULL << bw) - 1ULL));
    a = static_cast<int>(ua);
    cout << ((a ^ b) <= a ? "yes\n" : "no\n");
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