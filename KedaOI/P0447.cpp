#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
char a[N], b[N];
int f[N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), m = strlen(b + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m] << '\n';
    return 0;
}