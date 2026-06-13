#include <bits/stdc++.h>
using namespace std;
int n, m;
int getpre(int x1, int y1, int x2, int y2, vector <vector <long long int> > a) {
    return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    vector <vector <long long int> > a(n, vector <long long int> (m)),
                                     pre(n, vector <long long int> (m, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] + pre[i - 1][j - 1];
            // a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {

        }
    }
    return 0;
}