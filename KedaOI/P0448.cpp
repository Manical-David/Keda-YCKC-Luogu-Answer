#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, m, w[N][N];
int f[N][N];
vector <int> path;
void dfs(int i, int j) {
    if (i == 0) return;
    for (int a = 0; a <= j; a++) {
        if (f[i - 1][j - a] + w[i][a] == f[i][j]) {
            path.push_back(a);
            dfs(i - 1, j - a);
            return ;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << '\n';
    dfs(n, m);
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
        printf("%d %d\n", i + 1, path[i]);
    }
    return 0;
}