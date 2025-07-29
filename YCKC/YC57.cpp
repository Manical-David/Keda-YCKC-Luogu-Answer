#include <bits/stdc++.h>
using namespace std;
int main() {
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    double dist = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    cout << fixed << setprecision(3) << dist << endl;
    return 0;
}