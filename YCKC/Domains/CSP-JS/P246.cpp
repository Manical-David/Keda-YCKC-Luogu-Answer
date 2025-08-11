#include <bits/stdc++.h>
using namespace std;
const int MOD = 100003;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> dp(N + 1, 0);
    vector<int> prefix(N + 1, 0);
    dp[0] = 1;
    prefix[0] = 1;
    for (int i = 1; i <= N; ++i) {
        if (i <= K) {
            dp[i] = prefix[i - 1];
        } else {
            dp[i] = (prefix[i - 1] - prefix[i - K - 1] + MOD) % MOD;
        }
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }
    cout << dp[N] << endl;
    return 0;
}