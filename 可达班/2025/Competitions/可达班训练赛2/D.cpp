#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[0] = 0; 
    deque<int> dq;
    dq.push_back(0);// 维护单调
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - m) { // 越界
            dq.pop_front();
        }
        dp[i] = dp[dq.front()] + a[i];
        while (!dq.empty() && dp[dq.back()] >= dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ll ans = LLONG_MAX;
    for (int i = max(1, n - m + 1); i <= n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}