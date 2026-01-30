#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll NEG = 1ll - 4e18;
void solve() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> divs(m + 1);
    for (int i = 2; i <= min(n, m); ++i) {
        for (int j = i; j <= m; j += i) divs[j].push_back(i);
    }
    vector<ll> dp(n + 1, NEG);
    dp[0] = 0;
    for (int x = 1; x <= m; ++x) {
        if (divs[x].empty()) continue;
        auto &vx = divs[x];
        sort(vx.begin(), vx.end(), greater <int> ());
        for (int k : vx) {
            if (k > n) continue;
            if (dp[k - 1] <= NEG / 2) continue; 
            int cnt = 0;
            int tmp = x;
            while (tmp % k == 0) {
                tmp /= k;
                ++cnt;
            }
            if (cnt > 0) dp[k] = max(dp[k], dp[k - 1] + cnt);
        }
    }
    cout << dp[n] << '\n';
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