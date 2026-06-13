#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
ll modinv(ll x) { return modpow(x, MOD - 2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    struct Case { int N; vector<int> A; };
    vector<Case> cases;
    cases.reserve(T);
    int global_maxA = 0;
    for (int tc = 0; tc < T; ++tc) {
        int N; cin >> N;
        cases.push_back({N, vector<int>(N)});
        for (int i = 0; i < N; ++i) {
            cin >> cases.back().A[i];
            global_maxA = max(global_maxA, cases.back().A[i]);
        }
    }

    // SPF (linear sieve) up to global_maxA
    vector<int> spf(global_maxA + 1);
    vector<int> primes;
    if (global_maxA >= 2) {
        for (int i = 2; i <= global_maxA; ++i) {
            if (spf[i] == 0) { spf[i] = i; primes.push_back(i); }
            for (int p : primes) {
                long long v = 1LL * p * i;
                if (p > spf[i] || v > global_maxA) break;
                spf[v] = p;
            }
        }
    }
    spf[1] = 1;

    for (auto &cs : cases) {
        int N = cs.N;
        auto &A = cs.A;
        vector<vector<pair<int,int>>> facts(N);
        facts.assign(N, {});
        struct Info { int mx = 0, cnt = 0, snd = 0; };
        unordered_map<int, Info> mp;
        mp.reserve(N * 3);

        // factor each A[i], update prime infos
        for (int i = 0; i < N; ++i) {
            int x = A[i];
            while (x > 1) {
                int p = spf[x];
                int e = 0;
                while (x % p == 0) { x /= p; ++e; }
                facts[i].push_back({p, e});
                Info &inf = mp[p];
                if (e > inf.mx) { inf.snd = inf.mx; inf.mx = e; inf.cnt = 1; }
                else if (e == inf.mx) { inf.cnt++; }
                else if (e > inf.snd) { inf.snd = e; }
            }
        }

        // compute full-lcm
        ll full = 1;
        unordered_map<int,ll> invReduce; invReduce.reserve(mp.size());
        for (auto &kv : mp) {
            int p = kv.first;
            Info &inf = kv.second;
            full = full * modpow(p, inf.mx) % MOD;
            if (inf.cnt == 1 && inf.mx != inf.snd) {
                int diff = inf.mx - inf.snd;
                ll reduce = modpow(p, diff);
                invReduce[p] = modinv(reduce);
            }
        }

        // answers
        for (int i = 0; i < N; ++i) {
            ll ans = full;
            for (auto &pe : facts[i]) {
                int p = pe.first, e = pe.second;
                auto it = mp.find(p);
                if (it == mp.end()) continue;
                Info &inf = it->second;
                if (inf.cnt == 1 && e == inf.mx) {
                    ans = ans * invReduce[p] % MOD;
                }
            }
            cout << ans << (i + 1 == N ? '\n' : ' ');
        }
    }
    return 0;
}