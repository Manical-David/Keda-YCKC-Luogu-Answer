#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int _n = 0) : n(_n), f(n+1, 0) {}
    void init(int _n) { n = _n; f.assign(n+1, 0); }
    void add(int i, ll v) {
        if (v < 0) v += MOD;
        for (++i; i <= n; i += i & -i) {
            f[i] += v;
            if (f[i] >= MOD) f[i] -= MOD;
        }
    }
    ll sum(int i) const {
        if (i < 0) return 0;
        ll s = 0;
        for (++i; i > 0; i -= i & -i) {
            s += f[i];
            if (s >= MOD) s -= MOD;
        }
        return s;
    }
    ll range_sum(int l, int r) const {
        if (r < l) return 0;
        ll res = sum(r);
        if (l > 0) {
            res -= sum(l-1);
            if (res < 0) res += MOD;
        }
        return res;
    }
};
struct Event { int L, newp, val; };
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    vector<vector<int>> pos(N+2);
    for (int i = 1; i <= N; ++i) {
        if (A[i] <= N) pos[A[i]].push_back(i);
    }
    vector<int> inte;
    vector<int> idx(N+2, -1);
    for (int x = 1; x <= N; ++x) {
        if ((int)pos[x].size() >= x) {
            idx[x] = inte.size();
            inte.push_back(x);
        }
    }
    vector<vector<int>> cds(inte.size());
    for (size_t t = 0; t < inte.size(); ++t) {
        int x = inte[t];
        int cnt = pos[x].size();
        auto &c = cds[t];
        c.push_back(0);
        for (int r = 0; r <= cnt - x; ++r) {
            int L = (r == 0 ? 0 : pos[x][r-1]);
            int R = pos[x][r] - 1;
            int newp = pos[x][r + x - 1];
            c.push_back(L);
            c.push_back(R);
            c.push_back(newp);
        }
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
    }
    vector<Fenwick> ftx;
    ftx.reserve(inte.size());
    for (size_t t = 0; t < inte.size(); ++t)
        ftx.emplace_back(cds[t].size());

    Fenwick ft_all(N+1);
    vector<vector<Event>> evs(N+1);
    for (int x = 1; x <= N; ++x) {
        int cnt = pos[x].size();
        if (cnt < x) continue;
        for (int r = 0; r <= cnt - x; ++r) {
            int L = (r == 0 ? 0 : pos[x][r-1]);
            int R = pos[x][r] - 1;
            int newp = pos[x][r + x - 1];
            evs[R].push_back({L, newp, x});
        }
    }

    vector<ll> dp(N+1);
    dp[0] = 1;
    ft_all.add(0, 1);
    for (int p = 0; p <= N; ++p) {
        for (auto &ev : evs[p]) {
            ll tot = ft_all.range_sum(ev.L, p);
            ll bad = 0;
            int xi = idx[ev.val];
            if (xi != -1) {
                auto &c = cds[xi];
                int cl = lower_bound(c.begin(), c.end(), ev.L) - c.begin();
                int cp = lower_bound(c.begin(), c.end(), p) - c.begin();
                bad = ftx[xi].range_sum(cl, cp);
            }
            ll s = tot - bad;
            s %= MOD;
            if (s < 0) s += MOD;
            if (s != 0) {
                dp[ev.newp] += s;
                if (dp[ev.newp] >= MOD) dp[ev.newp] -= MOD;
                ft_all.add(ev.newp, s);
                if (xi != -1) {
                    auto &c = cds[xi];
                    int cn = lower_bound(c.begin(), c.end(), ev.newp) - c.begin();
                    ftx[xi].add(cn, s);
                }
            }
        }
    }
    ll ans = 0;
    for (int p = 1; p <= N; ++p) {
        ans += dp[p];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}