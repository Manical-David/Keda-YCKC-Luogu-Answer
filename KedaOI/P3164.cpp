#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 7;
constexpr int M = N;
int a[N];
int f[M];
int n;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n < 2) {
        cout << "NO\n";
        return 0;
    }

    int sum = accumulate(a + 1, a + n + 1, 0);
    if (sum & 1) {
        cout << "NO\n";
        return 0;
    }
    int maxx = *max_element(a + 1, a + 1 + n);
    if (maxx > sum / 2) {
        cout << "NO\n";
        return 0;
    }
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = sum / 2; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + 1);
        }
    }
    if (f[sum / 2] > 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}