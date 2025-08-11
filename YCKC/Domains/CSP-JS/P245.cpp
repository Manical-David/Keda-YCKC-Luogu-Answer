#include <bits/stdc++.h>
using namespace std;
long long dp[65];
void a() {
    dp[0] = 1;
    dp[1] = 1;
    for (int n = 2; n <= 65; n++) {
        dp[n] = dp[n - 1] + 2 * dp[n - 2];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
