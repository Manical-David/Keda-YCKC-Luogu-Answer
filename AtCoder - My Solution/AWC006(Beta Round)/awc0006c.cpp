#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, D;
    cin >> N >> M >> D;
    long long ans = 0;
    for (int i = 0, T; i < N; ++i) {
        cin >> T;
        if (T > M) {
            int diff = T - M;
            ans += (diff + D - 1) / D;
        }
    }
    cout << ans << '\n';
    return 0;
}