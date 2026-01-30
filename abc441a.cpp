#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y, p, q;
    cin >> p >> q >> x >> y;
    int xmin = p, xmax = p + 99, ymin = q, ymax = q + 99;
    if (x <= xmax && x >= xmin && y >= ymin && y <= ymax) {
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}