#include <bits/stdc++.h>
using namespace std;
int a[10086][10086];
inline void dfs(int i, int j) {
    if(a[i][j - 1] == 2 || a[i][j + 1] == 2 || a[i - 1][j] == 2 || a[i + 1][j] == 2) {
        a[i][j] = 2;
        if(a[i][j + 1] != 1) a[i][j + 1] = 2;
        if(a[i][j - 1] != 1) a[i][j - 1] = 2;
        if(a[i + 1][j] != 1) a[i + 1][j] = 2;
        if(a[i - 1][j] != 1) a[i - 1][j]
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i <= 11; i++) {
        a[i][0] = 2;
        a[0][i] = 2;
        a[11][i] = 2;
        a[i][11] = 2;
    }
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(a[i][j] != 1) dfs(i, j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(a[i][j] == 0) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}