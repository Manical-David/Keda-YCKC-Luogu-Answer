#include <bits/stdc++.h>
using namespace std;
int main() {
    double x;
    int n;
    cin >> x >> n;
    double res = x;
    for (int i = 1; i <= n; ++i) {
        res = sqrt(i + res);
    }
    cout << fixed << setprecision(2) << res << endl;
    return 0;
}