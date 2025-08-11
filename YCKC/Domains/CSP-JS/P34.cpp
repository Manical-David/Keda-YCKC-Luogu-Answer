#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        long long k, n, a, b;
        cin >> k >> n >> a >> b;
        long long minn = n * b;
        if (minn >= k) {
            cout << -1 << '\n';
            continue;
        }
        long long bin = k - minn;
        long long diff = a - b;
        long long maxx = (bin - 1) / diff;
        long long res = min(maxx, n);
        cout << res << '\n';
    }
    return 0;
}