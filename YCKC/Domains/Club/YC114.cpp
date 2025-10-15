#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int ans = 0;
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++) {
        ans += i;
    }
    cout << ans << '\n';
    return 0;
}