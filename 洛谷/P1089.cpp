#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, s = 0, y = 0;
    for (int i = 1; i <= 12; i++) {
        cin >> y;
        n = n + 300 - y;
        if (n < 0) {
            cout << "-" << i;
            return 0;
        }
        while (n >= 100) {
            n -= 100;
            s += 100;
        }
    }
    cout << s * 1.2 + n << '\n';
    return 0;
}
