#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans, x, s, n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s += x;
        if (s > 0 && i != 1)
            ans += s;
    }
    cout << ans;
    return 0;
}
