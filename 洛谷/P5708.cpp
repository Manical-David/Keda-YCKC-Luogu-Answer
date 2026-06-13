#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    double ans = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(1) << ans;
    return 0;
}