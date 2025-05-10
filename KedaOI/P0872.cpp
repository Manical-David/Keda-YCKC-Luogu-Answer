#include <bits/stdc++.h>
using namespace std;
int minBoxes(int n) {
    int minTotal = INT_MAX;
    for (int y = 0; y <= n / 5; ++y) {
        int remaining = n - 5 * y;
        if (remaining >= 0 && remaining % 3 == 0) {
            int x = remaining / 3;
            minTotal = min(minTotal, x + y);
        }
    }
    return (minTotal != INT_MAX) ? minTotal : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << minBoxes(n) << '\n';
    }
    return 0;
}