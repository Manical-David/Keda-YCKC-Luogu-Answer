#include <bits/stdc++.h>
using namespace std;
constexpr int N = 102;
void solve() {
    int n;
    cin >> n;
    cout << int((sqrt(2 * n) - 1) / 2) << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}