#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            g[i][j] = (s[j - 1] == '1');
        }
    }
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i][j];
        }
    }
    int ans = INT_MAX;
    for (int t = 1; t <= n; ++t) {
        for (int b = t; b <= n; ++b) {
            int l = 1, r = 1, cnt = 0;
            while (r <= m) {
                int bl = sum[b][r] - sum[t - 1][r] - sum[b][l - 1] + sum[t - 1][l - 1];
                if (bl < k) {
                    ++r;
                } else {
                    while (l <= r) {
                        int bl2 = sum[b][r] - sum[t - 1][r] - sum[b][l - 1] + sum[t - 1][l - 1];
                        if (bl2 >= k) {
                            ans = min(ans, (b - t + 1) * (r - l + 1));
                            ++l;
                        } else {
                            break;
                        }
                    }
                    ++r;
                }
            }
        }
    }
    if (ans == INT_MAX) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}