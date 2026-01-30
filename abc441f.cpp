#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)(-9e18);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> P(n+1);
    vector<ll> V(n+1);
    for (int i = 1; i <= n; ++i) cin >> P[i] >> V[i];
    vector<vector<ll>> pref(n+1, vector<ll>(m+1, NEG));
    pref[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        // copy previous
        pre
        
        f[i] = pref[i-1];
        int p = P[i];
        ll v = V[i];
        for (int w = m; w >= p; --w) {
            if (pref[i-1][w-p] != NEG)
                pref[i][w] = max(pref[i][w], pref[i-1][w-p] + v);
        }
    }
    vector<vector<ll>> suf(n+2, vector<ll>(m+1, NEG));
    suf[n+1][0] = 0;
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i+1];
        int p = P[i];
        ll v = V[i];
        for (int w = m; w >= p; --w) {
            if (suf[i+1][w-p] != NEG)
                suf[i][w] = max(suf[i][w], suf[i+1][w-p] + v);
        }
    }
    vector<vector<ll>> sufmax(n+2, vector<ll>(m+1, NEG));
    for (int i = 1; i <= n+1; ++i) {
        ll cur = NEG;
        for (int w = 0; w <= m; ++w) {
            cur = max(cur, suf[i][w]);
            sufmax[i][w] = cur;
        }
    }
    ll max_all = 0;
    for (int w = 0; w <= m; ++w) if (pref[n][w] != NEG) max_all = max(max_all, pref[n][w]);
    string ans;
    ans.resize(n);
    for (int i = 1; i <= n; ++i) {
        ll bw = NEG;
        for (int w = 0; w <= m; ++w) {
            if (pref[i-1][w] == NEG) continue;
            int rem = m - w;
            ll r = sufmax[i+1][rem];
            if (r == NEG) continue;
            bw = max(bw, pref[i-1][w] + r);
        }
        if (bw < max_all) {
            ans[i-1] = 'A';
            continue;
        }
        bool fl = false;
        int pi = P[i];
        ll vi = V[i];
        for (int w = 0; w <= m - pi; ++w) {
            if (pref[i-1][w] == NEG) continue;
            int rem = m - (w + pi);
            ll r = sufmax[i+1][rem];
            if (r == NEG) continue;
            if (pref[i-1][w] + vi + r >= max_all) { fl = true; break; }
        }
        ans[i-1] = fl ? 'B' : 'C';
    }

    cout << ans << '\n';
    return 0;
}