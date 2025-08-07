#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int a1 = 0, a2 = 0, n, a, cnt = 0;
    cin >> n;
    while(n--) {
        cin >> a;
        cnt += a;
        if(a & 1) a1++;//偶
        else a2++; //奇
    }
    if(cnt % 2 == 1 || (a1 >= 1 && a2 >= 1)) cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}