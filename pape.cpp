#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (g[i - 1][j - 1] == '1' ? 1 : 0);
        }
    }
    int ans = -0x3f3f3f;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                for (int r = l; r < m; ++r) {
                    int cnt = pre[j + 1][r + 1] - pre[i][r + 1] - pre[j + 1][l] + pre[i][l];
                    if (cnt >= k) {
                        int S = (j - i + 1) * (r - l + 1);
                        if (S < ans) {
                            ans = S;
                        }
                    }
                }
            }
        }
    }
    cout << (ans == -0x3f3f3f ? 0 : ans) << '\n';
    return 0;
}// 不就是二位前缀和模版题吗