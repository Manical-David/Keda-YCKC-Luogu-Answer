#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    if (!(cin >> N))
        return 0;
    vector<ll> W(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    int Q;
    cin >> Q;
    int B = max(1, (int)sqrt(N));
    int nb = (N + B - 1) / B;
    vector<char> uni(nb, 1);
    vector<ll> bA(nb, 0);
    vector<int> bc(nb, 0);
    vector<ll> Aarr(N + 1, 0);
    vector<int> carr(N + 1, 0);
    for (int b = 0; b < nb; b++)
    {
        bA[b] = 0;
        bc[b] = 0;
    }
    auto block_id = [&](int i)
    { return (i - 1) / B; };
    auto block_range = [&](int b)
    { int l=b*B+1; int r=min(N,(b+1)*B); return pair<int,int>(l,r); };
    auto materialize = [&](int b)
    {
        if (!uni[b])
            return;
        auto pr = block_range(b);
        for (int i = pr.first; i <= pr.second; i++)
        {
            Aarr[i] = bA[b];
            carr[i] = bc[b];
        }
        uni[b] = 0;
    };
    auto get_pair = [&](int i) -> pair<ll, int>
    {
        int b = block_id(i);
        if (uni[b])
            return {bA[b], bc[b]};
        return {Aarr[i], carr[i]};
    };
    for (int qi = 0; qi < Q; ++qi)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int v;
            cin >> v;
            auto prv = get_pair(v);
            ll A = prv.first;
            int c = prv.second;
            ll L = (c == 0 ? A : A - W[v]);
            int bid = block_id(v);
            for (int b = 0; b < bid; b++)
            {
                uni[b] = 1;
                bA[b] = L;
                bc[b] = 0;
            }
            auto rng = block_range(bid);
            materialize(bid);
            for (int i = rng.first; i <= min(rng.second, v); i++)
            {
                Aarr[i] = L;
                carr[i] = 0;
            }
        }
        else if (tp == 2)
        {
            int v;
            cin >> v;
            auto prv = get_pair(v);
            ll A = prv.first;
            int c = prv.second;
            ll L = (c == 0 ? A : A - W[v]);
            ll Anew = L + W[v];
            int bid = block_id(v);
            for (int b = 0; b < bid; b++)
            {
                uni[b] = 1;
                bA[b] = Anew;
                bc[b] = -1;
            }
            auto rng = block_range(bid);
            materialize(bid);
            for (int i = rng.first; i <= min(rng.second, v); i++)
            {
                Aarr[i] = Anew;
                carr[i] = -1;
            }
        }
        else
        {
            ll x;
            cin >> x;
            ll ans = 0;
            for (int b = 0; b < nb; b++)
            {
                auto rng = block_range(b);
                int l = rng.first, r = rng.second;
                if (uni[b])
                {
                    ll A = bA[b];
                    int c = bc[b];
                    if (c == 0)
                    {
                        if (A <= x)
                            ans += (r - l + 1);
                        ll thr = x - A;
                        if (thr >= W[1])
                        {
                            int p = int(upper_bound(W.begin() + 1, W.begin() + N + 1, thr) - W.begin()) - 1;
                            if (p >= l)
                            {
                                int rr = min(r, p);
                                if (rr >= l)
                                    ans -= (rr - l + 1);
                            }
                        }
                    }
                    else
                    {
                        ll thr = A - x;
                        if (!(thr > W[N]))
                        {
                            int pos;
                            if (thr <= W[1])
                                pos = 1;
                            else
                                pos = int(lower_bound(W.begin() + 1, W.begin() + N + 1, thr) - W.begin());
                            if (pos <= r)
                            {
                                int llpos = max(l, pos);
                                if (llpos <= r)
                                    ans += (r - llpos + 1);
                            }
                        }
                        if (A <= x)
                            ans -= (r - l + 1);
                    }
                }
                else
                {
                    for (int i = l; i <= r; i++)
                    {
                        ll Ai = Aarr[i];
                        int ci = carr[i];
                        ll Li = (ci == 0 ? Ai : Ai - W[i]);
                        if (Li <= x && x < Li + W[i])
                            ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}