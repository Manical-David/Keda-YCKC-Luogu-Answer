#include <bits/stdc++.h>
using namespace std;
void solve() {
    int tim1, tim2;
    char ch;
    cin >> tim1 >> ch >> tim2;
    int x, ans = 0;
    cin >> x;
    int i = tim1 * 60 + tim2;
    do {
        if(i / 60 % 10 == i % 60 / 10 && i / 60 / 10 == i % 60 % 10) ans++;
        i = i + x;
        i %= 1440;
    } while(i != tim1 * 60 + tim2);
    cout << ans << '\n';
}
int T;
int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}