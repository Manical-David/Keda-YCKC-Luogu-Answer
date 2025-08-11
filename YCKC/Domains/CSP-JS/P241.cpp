#include <bits/stdc++.h>
using namespace std;
int n, o = 1, a[1145][1145];
void dfs(int x, int l, int q) {
    if (x == 2) {
        a[l][q] = 0;
        return;
    }
    for (int i = l; i <= l + x / 2 - 1; i++) {
        for (int j = q; j <= q + x / 2 - 1; j++) {
            a[i][j] = 0;
        }
    }
    dfs(x / 2, l + x / 2, q);
    dfs(x / 2, l + x / 2, q + x / 2);
    dfs(x / 2, l, q + x / 2);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        o *= 2;
    }
    for (int i = 1; i <= o; i++) {
        for (int j = 1; j <= o; j++) {
            a[i][j] = 1;
        }
    }
    dfs(o, 1, 1);
    for (int i = 1; i <= o; i++) {
        for (int j = 1; j <= o - 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << a[i][o] << endl;
    }
    return 0;
}