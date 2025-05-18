#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, long long> factor = {
        // 长度
        {"km", 1000000LL},
        {"m",    1000LL},
        {"mm",      1LL},
        // 重量
        {"kg", 1000000LL},
        {"g",    1000LL},
        {"mg",      1LL}
    };
    int N;
    cin >> N;
    while (N--) {
        long long x;
        string u1, eq, qm, u2;
        cin >> x >> u1 >> eq >> qm >> u2;
        long long ans = x * factor[u1] / factor[u2];
        cout << x << ' ' << u1 << ' ' << eq
             << ' ' << ans << ' ' << u2 << '\n';
    }
    return 0;
}
