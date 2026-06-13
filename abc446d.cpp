#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    unordered_map<int, int> dp;
    int ans = 0;
    for (int x : A) {
        if (dp.find(x - 1) != dp.end()) {
            dp[x] = dp[x - 1] + 1;
        } else {
            dp[x] = 1;
        }
        ans = max(ans, dp[x]);
    }
    
    cout << ans << endl;
    return 0;
}