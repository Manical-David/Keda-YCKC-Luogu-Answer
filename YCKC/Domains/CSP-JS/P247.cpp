#include<bits/stdc++.h>
using namespace std;
int n, m, f[35][35];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)f[i][1] = 1;
    for(int j = 1; j <= m; j++)f[1][j] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(i % 2 == 0 && j % 2 == 0)f[i][j] = 0;
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[n][m];
    return 0;
}
