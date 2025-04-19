#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> dp[i];
    }
    int fen = 0;
    for (int num : dp) {
        fen += num;
    }
    int minMax = fen;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int P1 = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                P1 += dp[i];
            }
        }
        int P2 = fen - P1;
        minMax = min(minMax, max(P1, P2));
    }
    cout << minMax << endl;
    return 0;
}