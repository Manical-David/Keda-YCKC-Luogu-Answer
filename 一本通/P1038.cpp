#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int ans = y / x;
    if(y % x > 0) ans ++;
    cout << n - ans;
    return 0;
}