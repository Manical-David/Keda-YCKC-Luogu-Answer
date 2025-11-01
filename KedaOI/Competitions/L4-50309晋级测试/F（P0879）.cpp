#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, minn, maxx;
    cin >> n >> minn >> maxx;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <vector <bool> > dp(n + 1, vector <bool> (maxx + 1, false));
    dp[0][minn] = true;
    for (int i = 1; i <= n; i++) {
        int c = a[i - 1];
        for (int v = 0; v <= maxx; v++) {
            // 枚举情况
            if (dp[i - 1][v]) {
                // 调高音量
                if (v + c <= maxx) {
                    dp[i][v + c] = true;
                }
                // 调低音量
                if (v - c >= 0) {
                    dp[i][v - c] = true;
                }
            }
        }
    }
    for (int v = maxx; v >= 0; v--) {
        if (dp[n][v]) {
            cout << v << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}