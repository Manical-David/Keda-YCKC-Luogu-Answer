#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        ll s, c;
        cin >> s >> c;
        cnt[s] += c;
    }
    for (auto it = cnt.begin(); it != cnt.end(); ++it) { // get the dianoglars anymore.
        ll carry = it->second / 2;
        it->second %= 2;
        if (carry) cnt[it->first * 2] += carry;
    }
    ll ans = 0;
    for (auto &p : cnt) ans += p.second;
    cout << ans << '\n';
    return 0;
}