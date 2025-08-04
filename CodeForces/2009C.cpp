#include <bits/stdc++.h>
using namespace std;
int t, x, y, k;
int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y >> k;
        int xs = x / k, ys = y / k;
        if (xs * k < x)
            xs++;
        if (ys * k < y)
            ys++;
        if (xs <= ys)
            cout << 2 * ys << endl;
        else if (xs > ys)
            cout << 2 * xs - 1 << endl;
    }
    return 0;
}
