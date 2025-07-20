#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    double x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    cout << fixed << setprecision(7) << a * pow(x, 3) + b * pow(x, 2) + c * x + d;
    return 0;
}