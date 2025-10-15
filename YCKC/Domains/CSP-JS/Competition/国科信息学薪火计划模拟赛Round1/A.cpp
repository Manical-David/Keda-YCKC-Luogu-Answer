#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("aisle.in", "r", stdin);
    freopen("aisle.out", "w", stdout);
    int n, l, w, x, y, a;
    cin >> n >> l >> w >> x >> y >> a;
    int xs = l / x;
    if (xs == 0) {
        cout << -1 << '\n';
        return 0;
    }
    int cntns = a + 2 * y;
    int nx = w / cntns;
    for (int k = nx; k >= 1; --k) {
        int tong = w - k * cntns;
        if (tong < 0) {
            continue;
        }
        int mid = tong / y;
        int cnt = (2 * k + mid) * xs;

        if (cnt >= n) {
            cout << 2 * k * xs << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}