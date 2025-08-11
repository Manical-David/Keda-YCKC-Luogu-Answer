#include <bits/stdc++.h>
using namespace std;
double solve(int n, double x) {
    if (n == 0) return 1.0;
    if (n == 1) return 2.0 * x;
    double h0 = 1.0;
    double h1 = 2.0 * x;
    double hn;
    for (int i = 2; i <= n; ++i) {
        hn = 2 * x * h1 - 2 * (i - 1) * h0;
        h0 = h1;
        h1 = hn;
    }
    return h1;
}
int main() {
    int n;
    double x;
    cin >> n >> x;
    cout << fixed << setprecision(0) << solve(n, x) << endl;
    return 0;
}