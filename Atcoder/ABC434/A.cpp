#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 1;
    a *= 1000;
    do {
        ans++;
    } while (ans * b <= a);
    cout << ans << '\n';
    return 0;
}