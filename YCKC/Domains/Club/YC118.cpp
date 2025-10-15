#include <bits/stdc++.h>
using namespace std;
bool check(int n) {
    if(n % 2 == 1) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int m, n;
    cin >> m >> n;
    int ans = 0;
    for(int i = m; i <= n; i++) {
        if(check(i)) {
            ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}