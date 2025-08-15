#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double n;
    cin >> n;
    bool flag = (n < 0);
    if(flag) cout << fixed << setprecision(6) << -1 * pow(n, 1 / 3);
    else cout << fixed << setprecision(6) << pow(n, 1 / 3);
    return 0;
}