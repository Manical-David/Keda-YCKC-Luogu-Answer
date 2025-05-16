#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N][N], b[N][N], ans[N][N];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[j][i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}