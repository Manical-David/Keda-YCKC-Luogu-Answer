#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, r;
    cin >> h >> r;
    double v = 3.14 * r * r * h;
    int ans = ceil(20000 / v);
    cout << ans << endl;
    return 0;
}