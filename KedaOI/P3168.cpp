#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, M = 1e5 + 7;
int n, a[N], f[M];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    int m = sum / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
                f[j] = max(f[j], f[j - a[i]] + a[i]);
            
        }
    }
    cout << abs(sum - f[m] - f[m]) << '\n';
    return 0;
}