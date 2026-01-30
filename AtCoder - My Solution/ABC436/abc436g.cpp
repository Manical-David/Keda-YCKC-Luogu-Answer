#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 998244353;
constexpr int G = 3;
int modpow(int a, long long e = MOD - 2) {
    long long r = 1, x = a;
    while (e) {
        if (e & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        e >>= 1;
    }
    return (int)r;
}
void ntt(vector<int> &a, bool inv) {
    int n = (int)a.size();
    static vector<int> rev;
    static vector<int> ros{0, 1};
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    if ((int)ros.size() < n) {
        int k = __builtin_ctz(ros.size());
        ros.resize(n);
        while ((1 << k) < n) {
            int z = modpow(G, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i)
                ros[2 * i] = ros[i], ros[2 * i + 1] = (int)((1LL * ros[i] * z) % MOD);
            ++k;
        }
    }
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len){
            for (int j = 0; j < len; j++) {
                int u = a[i + j];
                int v = (int)((1LL * a[i + j + len] * ros[len + j]) % MOD);
                a[i + j] = u + v;
                if (a[i + j] >= MOD)
                    a[i + j] -= MOD;
                a[i + j + len] = u - v;
                if (a[i + j + len] < 0)
                    a[i + j + len] += MOD;
            }
        }
    }
    if (inv) {
        reverse(a.begin() + 1, a.end());
        int inv_n = modpow(n);
        for (int &x : a)
            x = (int)((1LL * x * inv_n) % MOD);
    }
}
vector<int> conv(const vector<int> &a, const vector<int> &b, int cntn = -1) {
    int n = (int)a.size(), m = (int)b.size();
    if (!n || !m)
        return {};
    int sz = 1;
    int nw = (cntn == -1) ? (n + m - 1) : min(n + m - 1, cntn);
    while (sz < n + m - 1)
        sz <<= 1;
    vector<int> fa(sz), fb(sz);
    for (int i = 0; i < n; i++)
        fa[i] = a[i];
    for (int i = 0; i < m; i++)
        fb[i] = b[i];
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < sz; i++)
        fa[i] = (int)(1LL * fa[i] * fb[i] % MOD);
    ntt(fa, true);
    fa.resize(nw);
    return fa;
}
vector<int> pts(vector<int> a) {
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    return a;
}
int bmtt(vector<int> P, vector<int> Q, long long n) {
    P = pts(P);
    Q = pts(Q);
    int d = (int)Q.size() - 1;
    if ((int)P.size() < d)
        P.resize(d, 0);
    while (n) {
        vector<int> qe(Q.size());
        for (size_t i = 0; i < Q.size(); ++i)
            qe[i] = (i & 1) ? (MOD - Q[i]) % MOD : Q[i];
        vector<int> U = conv(P, qe, 2 * d + 1);
        vector<int> V = conv(Q, qe, 2 * d + 1);
        vector<int> pn(d);
        vector<int> qn(d + 1);
        int start = n & 1;
        for (int i = 0; i < d; i++) {
            int idx = 2 * i + start;
            pn[i] = (idx < (int)U.size()) ? U[idx] : 0;
        }
        for (int i = 0; i <= d; i++) {
            int idx = 2 * i;
            qn[i] = (idx < (int)V.size()) ? V[idx] : 0;
        }
        P = pts(pn);
        Q = pts(qn);
        if ((int)Q.size() == 0)
            return 0;
        n >>= 1;
        d = (int)Q.size() - 1;
        if ((int)P.size() < d)
            P.resize(d, 0);
    }
    int q0 = Q.empty() ? 1 : Q[0];
    int invq0 = modpow(q0);
    int p0 = P.empty() ? 0 : P[0];
    return (int)((1LL * p0 * invq0) % MOD);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    long long M;
    if (!(cin >> N >> M))
        return 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> Q = {1};
    for (int a : A) {
        if (a == 1) {
            vector<int> R(a + 1);
            R[0] = 1;
            R[a] = (MOD - 1);
            Q = conv(Q, R);
        }
        else {
            vector<int> R(a + 1);
            R[0] = 1;
            R[a] = (MOD - 1);
            Q = conv(Q, R);
        }
    }
    {
        vector<int> R(2);
        R[0] = 1;
        R[1] = (MOD - 1);
        Q = conv(Q, R);
    }
    // p(x) = 1
    vector<int> P(1, 1);
    int ans = bmtt(P, Q, M);
    cout << ans << '\n';
    return 0;
}