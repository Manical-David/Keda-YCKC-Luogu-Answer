#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, w[N];
int f[N][3];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    f[0][0] = f[0][1] = -0x3f3f3f3f;
    f[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
    }
    cout << max(f[n][1], f[n][2]);
    return 0;
}