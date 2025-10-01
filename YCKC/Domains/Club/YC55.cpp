#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double t;
    int n;
    cin >> t >> n;
    cout << fixed << setprecision(3) << t / n;
    cout << '\n' << n * 2 << '\n';
    return 0;
}