// max({(x - x[0] + 1), (y - y[0] + 1), (z - (k / x[0] * y[0]) + 1)}) md推了半天z+1WA声一片
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
signed main() {
    char c[N];
    int t, x, y, z, k;
    cin >> t;
    while (t--) {
        cin >> x >> y >> z >> k;
        int maxx = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (k % i == 0) {
                    int num = k / i;
                    if (num % j == 0) {
                        int dsw = num / j;
                        maxx = max(maxx, (x - i + 1) * (y - j + 1) * max(0ll, (z - dsw + 1)));
                    }
                }
            }
        }
        cout << maxx << "\n";
    }
    return 0;
}
