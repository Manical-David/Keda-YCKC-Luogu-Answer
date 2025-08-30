#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z, n, m;
    cin >> x >> y >> z >> n >> m;
    int cnt = 0;
    for (int a = 0; a <= m; ++a) {
        if (x * a > n) {
            continue;
        }
        if (a > m) {
            continue;
        }
        for (int b = 0; b <= m - a; ++b) {
            if (y * b > n - x * a) {
                continue;
            }
            int c = m - a - b;
            if (c >= 0 && c % z == 0) {
                int tong = x * a + y * b + (c / z);
                if (tong <= n) {
                    ++cnt;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
