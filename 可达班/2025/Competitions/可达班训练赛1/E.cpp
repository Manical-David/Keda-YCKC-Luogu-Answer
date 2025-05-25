#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
ll S;
vector<ll> a;
vector<ll> fact;
ll times_(ll x) { // Mune
    if (x > 20) return -1; // 20!爆
    ll res = 1;
    for (ll i = 2; i <= x; i++) {
        res *= i;
        if (res > S) return -1;
    }
    return res;
}
// 枚举
void dfs(const vector<ll>& vals, unordered_map<ll, unordered_map<int, ll>>& mp) {
    int m = (int)vals.size();
    function<void(int, ll, int)> go = [&](int idx, ll sum, int f) { // Taught by 陈丁's vector
        if (idx == m) {
            mp[sum][f]++;
            return;
        }
        ll val = vals[idx];
        ll val_fact = times_(val);
        go(idx + 1, sum, f);
        go(idx + 1, sum + val, f);
        if (val_fact != -1 && f + 1 <= k) {
            go(idx + 1, sum + val_fact, f + 1);
        }
    };
    go(0, 0, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> S;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mid = n / 2;
    vector<ll> l(a.begin(), a.begin() + mid);
    vector<ll> r(a.begin() + mid, a.end());
    unordered_map<ll, unordered_map<int, ll> > lm, rm;
    dfs(l, lm);
    dfs(r, rm);
    ll ans = 0;
    for (auto it1 = lm.begin(); it1 != lm.end(); ++it1) {
        ll sum_l = it1 -> first;
        auto& used_map_l = it1 -> second;
        ll tong = S - sum_l;
        if (rm.count(tong)) {
            auto& used_map_r = rm[tong];
            for (auto it2 = used_map_l.begin(); it2 != used_map_l.end(); ++it2) {
                int used_l = it2 -> first;
                ll cnt_l = it2 -> second;
                for (auto it3 = used_map_r.begin(); it3 != used_map_r.end(); ++it3) {
                    int used_r = it3 -> first;
                    ll cnt_r = it3 -> second;
                    if (used_l + used_r <= k) {
                        ans += cnt_l * cnt_r;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
