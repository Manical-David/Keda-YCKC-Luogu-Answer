#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int a[N][N], b[N][N], ans[N][N];
int main() {
    int n, m, gema;
    cin >> n >> m >> gema;
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
            ans[i][j] = gema * (a[i][j] + b[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}