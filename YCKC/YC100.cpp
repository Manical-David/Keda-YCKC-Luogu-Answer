#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x;
    cin >> x;
    bool c1, c2;
    c1 = (x % 2 == 0);
    c2 = (x > 4 && x <= 12);
    cout << (c1 && c2) << ' ' << (c1 || c2) << ' ' << ((!c1 && c2) || (c1 && !c2)) << ' ' << (!c1 && !c2);
    return 0;
}