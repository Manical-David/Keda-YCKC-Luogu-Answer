#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << '\n' << fixed << setprecision(1) << (double)(a + b + c) / 3;
    return 0;
}