#include <bits/stdc++.h>
using namespace std;
const int MOO = 1e9 + 7;
int fpow(int b, int e, int m) {
    int res = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            res = (res * b) % m;
        }
        b = (b * b) % m;
        e /= 2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int rm[n];
    rm[n-1] = INT_MAX;
    for (int i = n-2; i >= 0; --i) {
        rm[i] = min(a[i+1], rm[i+1]);
    }
    int lm = INT_MIN;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        bool lok = (i == 0) ? true : (lm <= a[i]);
        bool r_ok = (i == n-1) ? true : (rm[i] >= a[i]);
        if (lok && r_ok) {
            m++;
        }
        if (i < n-1) {
            lm = max(lm, a[i]);
        }
    }
    int c = n - m;
    int ans;
    if (c == 0) {
        ans = (fpow(2, n, MOO) - 1 + MOO) % MOO;
    } else {
        ans = fpow(2, m, MOO);
    }
    cout << ans << endl;
    return 0;
}