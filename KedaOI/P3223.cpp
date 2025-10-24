#include <bits/stdc++.h>
using namespace std;
constexpr int N = 107, M = 1e4 + 7;
int n, a[N], f[M];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            f[j] = min(f[j], f[j - i * i] + 1);
        }
    }
    cout << f[n];
    return 0;
}