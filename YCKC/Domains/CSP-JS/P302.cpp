#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m;
int f[N][N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for(int i = n- 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[1][1];
    return 0;
}