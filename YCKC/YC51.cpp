#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    double r1, r2;
    cin >> r1 >> r2;
    cout << fixed << setprecision(2) << 1 / ((1 / r1) + (1 / r2));
    return 0;
}