#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }
    int fen = 0;
    for (auto it : dp) {
        fen += it;
    }
    int minn = fen;
    for (int i = 0; i < (1 << n); i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tong += dp[j];
            }
        }
        int tongn = fen - tong;
        minn = min(minn, max(tong, tongn));
    }
    cout << minn;
    return 0;
}