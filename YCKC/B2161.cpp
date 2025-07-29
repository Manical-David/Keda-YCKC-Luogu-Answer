#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, m;
    cin >> x >> m;
    string res = "";
    while (x > 0) {
        int tong = x % m;
        if (tong < 10) {
            res += to_string(tong);
        } else {
            res += (char)('A' + tong - 10);
        }
        x /= m;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}