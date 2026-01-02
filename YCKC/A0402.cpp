#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a <= b) {
        cout << -1 << '\n';
        return 0;
    }
    double n = double((y - x) / (a - b));
    int k = (int)n + 1;
    cout << k << '\n';
    return 0;
}