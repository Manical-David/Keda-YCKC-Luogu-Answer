#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y;
    cin >> x >> y;
    int ans = (x + y) % 12;
    if(ans == 0) {
        cout << 12 << '\n';
        return 0;
    }
    cout << ans << '\n';
    return 0;
}