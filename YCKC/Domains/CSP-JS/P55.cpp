#include <bits/stdc++.h>
using namespace std;
int a[10][100010], sum[100005][11];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j <= 9; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][x]++;
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r, m;
        cin >> l >> r >> m;
        cout << sum[r][m] - sum[l - 1][m] << '\n';
    }
    return 0;
}