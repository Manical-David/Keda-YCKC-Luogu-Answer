#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int ans_ = y / x + bool(y % x);
    cout << n - ans_;   
    return 0;
}