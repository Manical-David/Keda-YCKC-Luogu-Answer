#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        bool flaga = true, falgb = true, flagc = true;
        int ans = 0;
        if(m <= a) ans += m;
        else ans += a;
        if(m <= b) ans += m;
        else ans += b;
        if(ans + c > 2 * m) ans = 2 * m;
        else ans += c;
        cout << ans << '\n';
    }
    return 0;
}