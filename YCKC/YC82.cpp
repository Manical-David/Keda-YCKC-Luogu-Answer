#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    if(x >= 0 && x < 5) return -x + 2.5;
    if(x >= 5 && x < 10) return 2 - 1.5 * (x - 3) * (x - 3);
    if(x >= 10 && x < 20) return x / 2 - 1.5;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double x;
    cin >> x;
    cout << fixed << setprecision(3) << f(x) << '\n';
    return 0;
}