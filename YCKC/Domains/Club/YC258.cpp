#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    cout << int(a + b + c) << '\n';
    cout << fixed << setprecision(1) << (a + b + c) / 3 << '\n';
    return 0;
}