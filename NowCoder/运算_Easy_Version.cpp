#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a;
    cin >> a;
    vector <int> dp(a * 9 + 1);
    for (int i = 1; i <= a; i++) {
        dp[i] = dp[i / 9]
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}