#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cat.in", "r", stdin);
    freopen("cat.out", "w", stdout);
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if (X * Y > 0 && abs(Y) < abs(X)) {
        if (X > 0) {
            if (Z > Y) {
                cout << -1 << '\n';
            } else {
                int dist = abs(Z) + abs(Y - Z) + abs(X - Y);
                cout << dist << '\n';
            }
        } else {
            if (Z < Y) {
                cout << -1 << '\n';
            } else {
                int dist = abs(Z) + abs(Y - Z) + abs(X - Y);
                cout << dist << '\n';
            }
        }
    } else {
        cout << abs(X) << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
