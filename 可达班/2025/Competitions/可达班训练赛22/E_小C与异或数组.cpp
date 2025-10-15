#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_BIT = 59;
ll solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(MAX_BIT + 1, 0);
    for (ll x : a) {
        if (x == 0) continue;
        for (int j = MAX_BIT; j >= 0; --j) {
            if ((x >> j) & 1) {
                if (b[j] == 0) {
                    b[j] = x;
                    break;
                } else {
                    x ^= b[j];
                }
            }
            if (x == 0) break;
        }
    }
    for (int i = 0; i <= MAX_BIT; ++i) {
        if (b[i] == 0) {
            return 1LL << i;
        }
    }
    return 1LL << (MAX_BIT + 1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    // freopen("xor.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
