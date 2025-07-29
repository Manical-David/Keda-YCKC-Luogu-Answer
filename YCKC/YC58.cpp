#include <bits/stdc++.h>
using namespace std;
int main() {
    double xa, ya, xb, yb, za, zb;
    cin >> xa >> ya >> za >> xb >> yb >> zb;
    double dist = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya) + (za - zb) * (za - zb));
    cout << fixed << setprecision(3) << dist << endl;
    return 0;
}