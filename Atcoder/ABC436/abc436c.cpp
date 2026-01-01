#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
ull key(ll r, ll c) {
    return ( (ull)r << 32 ) | (ull)c;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    ll n;
    int m;
    cin >> n >> m;
    unordered_set<ull> mp;
    mp.reserve((size_t)4 * m * 2);
    mp.max_load_factor(0.7f);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        ull k1 = key(x, y);
        ull k2 = key(x + 1, y);
        ull k3 = key(x, y + 1);
        ull k4 = key(x + 1, y + 1);
        if (mp.find(k1) == mp.end() && mp.find(k2) == mp.end() &&
            mp.find(k3) == mp.end() && mp.find(k4) == mp.end()) {
            mp.insert(k1);
            mp.insert(k2);
            mp.insert(k3);
            mp.insert(k4);
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}