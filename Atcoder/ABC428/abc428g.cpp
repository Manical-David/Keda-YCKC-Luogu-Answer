#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
ll modpow(ll a, ll e = MOD - 2)
{
    ll r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

bool pow_leq(ll a, int t, ll limit, ll &out)
{
    ll r = 1;
    for (int i = 0; i < t; i++)
    {
        if (r > limit / a)
            return false;
        r *= a;
    }
    out = r;
    return true;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N, U;
    if (!(cin >> N >> U))
        return 0;
    vector<int> cnt(U + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int b;
        cin >> b;
        if (b <= U)
            cnt[b]++;
    }
    int L = 0;
    while ((1 << L) <= U)
        ++L;
    while (L > 0 && (1 << (L - 1)) > U)
        --L;
    int Lmax = max(1, L);
    Lmax = 0;
    ll p = 1;
    while (p * 2 <= U)
    {
        p *= 2;
        ++Lmax;
    }
    Lmax = max(1, Lmax + 1);
    int maxlen = 0;
    ll cur = 1;
    while (cur * 2 <= U)
    {
        cur *= 2;
        ++maxlen;
    }
    maxlen = max(1, maxlen + 1);
    int G = maxlen + 1;
    vector<ll> inv(G + 1), phi(G + 1);
    for (int i = 1; i <= G; i++)
    {
        inv[i] = modpow(i);
    }
    for (int i = 0; i <= G; i++)
        phi[i] = i;
    for (int i = 2; i <= G; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= G; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    vector<ll> H(U + 1, 0);
    vector<ll> prev(U + 1, 0), curr(U + 1, 0);
    for (int i = 1; i <= U; i++)
        prev[i] = cnt[i] % MOD;
    for (int i = 1; i <= U; i++)
    {
        if (prev[i])
            H[i] = (H[i] + prev[i] * inv[1]) % MOD;
    }
    int upper_g = 1;
    for (int g = 2; g <= G; ++g)
    {
        fill(curr.begin(), curr.end(), 0);
        for (int d = 1; d <= U; ++d)
        {
            if (prev[d] == 0)
                continue;
            ll pv = prev[d];
            for (int m = d, q = 1; m <= U; m += d, ++q)
            {
                if (cnt[q] == 0)
                    continue;
                curr[m] = (curr[m] + pv * cnt[q]) % MOD;
            }
        }
        bool any = false;
        for (int i = 1; i <= U; i++)
        {
            if (curr[i])
            {
                any = true;
                H[i] = (H[i] + curr[i] * inv[g]) % MOD;
            }
        }
        if (!any)
            break;
        prev.swap(curr);
        upper_g = g;
    }
    auto int_root = [&](int x, int t) -> int
    {
        if (t == 1)
            return x;
        int lo = 1, hi = pow(x, 1.0 / t) + 2;
        if (hi > x)
            hi = x;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            ll pw;
            if (!pow_leq(mid, t, x, pw) || pw > x)
            {
                hi = mid - 1;
            }
            else
            {
                if (pw == x)
                    return mid;
                lo = mid + 1;
            }
        }
        return -1;
    };
    vector<ll> ans(U + 1, 0);
    for (int x = 2; x <= U; ++x)
    {
        ll res = 0;
        for (int t = 1; t <= upper_g; ++t)
        {
            int y = int_root(x, t);
            if (y <= 0)
                continue;
            res += (phi[t] * inv[t] % MOD) * H[y] % MOD;
            if (res >= MOD)
                res -= MOD;
        }
        ans[x] = res % MOD;
    }
    for (int x = 2; x <= U; ++x)
    {
        if (x > 2)
            cout << ' ';
        cout << ans[x];
    }
    cout << '\n';
    return 0;
}