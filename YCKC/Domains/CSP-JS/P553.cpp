#include <bits/stdc++.h>
#define int long long
using namespace std;
int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << lcm(a, lcm(b, c));
    return 0;
}
