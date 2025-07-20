#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(5) << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    return 0;
}