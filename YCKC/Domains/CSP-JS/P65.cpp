#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector<vector<double>> log10_w(n, vector<double>(m, 0.0));
    vector<vector<double>> log10_b(n, vector<double>(m, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) {
                log10_w[i][j] = log10(g[i][j]);
            } else {
                log10_b[i][j] = log10(g[i][j]);
            }
        }
    }
    vector<vector<double>> pre_w(n + 1, vector<double>(m + 1, 0.0));
    vector<vector<double>> pre_b(n + 1, vector<double>(m + 1, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pre_w[i + 1][j + 1] = pre_w[i + 1][j] + pre_w[i][j + 1] - pre_w[i][j] + log10_w[i][j];
            pre_b[i + 1][j + 1] = pre_b[i + 1][j] + pre_b[i][j + 1] - pre_b[i][j] + log10_b[i][j];
        }
    }
    double maxx = -1e18;
    for (int x1 = 0; x1 < n; ++x1) {
        for (int x2 = x1; x2 < n; ++x2) {
            for (int y1 = 0; y1 < m; ++y1) {
                for (int y2 = y1; y2 < m; ++y2) {
                    double sumw = pre_w[x2 + 1][y2 + 1] - pre_w[x1][y2 + 1] - pre_w[x2 + 1][y1] + pre_w[x1][y1];
                    double sumb = pre_b[x2 + 1][y2 + 1] - pre_b[x1][y2 + 1] - pre_b[x2 + 1][y1] + pre_b[x1][y1];
                    double cur = sumw - sumb;
                    if (cur > maxx) {
                        maxx = cur;
                    }
                }
            }
        }
    }
    double facp = maxx - floor(maxx);
    double val = pow(10, facp);
    long long ans = (long long)(val * 100000);
    cout << ans << '\n';
    return 0;
}