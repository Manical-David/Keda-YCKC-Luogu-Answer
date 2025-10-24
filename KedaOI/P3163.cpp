#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, target, a[N], f[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> target;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + 1);
        }
    }
    cout << max(-1, f[target]);
    return 0;
}