#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll, ll> ext_gcd(ll a, ll b) {
    if (b == 0) {
        return {1, 0};
    }
    auto [x1, y1] = ext_gcd(b, a % b);
    return {y1, x1 - (a / b) * y1};
}
ll mod_inv(ll a, ll m) {
    auto [x, y] = ext_gcd(a, m);
    return (x % m + m) % m;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int M, A, B;
    cin >> M >> A >> B;
    vector<vector<bool>> bad(M, vector<bool>(M, false));
    queue<pair<int, int>> q;
    for (int u = 0; u < M; ++u) {
        for (int v = 0; v < M; ++v) {
            if (u == 0 || v == 0) {
                bad[u][v] = true;
                q.emplace(u, v);
            }
        }
    }
    int d = gcd(B, M);
    int Bp = B / d;
    int Mp = M / d;
    int invBp = -1;
    if (d > 0 && Bp > 0) {
        if (Bp != 0) {
            invBp = mod_inv(Bp, Mp);
        }
    }
    while (!q.empty()) {
        auto [q_val, r_val] = q.front();
        q.pop();
        int t = (r_val - (A * q_val) % M) % M;
        if (t < 0) t += M;
        if (B == 0) {
            if (t == 0) {
                for (int p = 0; p < M; ++p) {
                    if (!bad[p][q_val]) {
                        bad[p][q_val] = true;
                        q.emplace(p, q_val);
                    }
                }
            }
            continue;
        }
        if (t % d != 0) {
            continue;
        }
        int tp = t / d;
        int p0 = (tp * invBp) % Mp;
        if (p0 < 0) p0 += Mp;
        for (int k = 0; k < d; ++k) {
            int p = p0 + k * Mp;
            if (!bad[p][q_val]) {
                bad[p][q_val] = true;
                q.emplace(p, q_val);
            }
        }
    }
    ll ans = 0;
    for (int u = 1; u < M; ++u) {
        for (int v = 1; v < M; ++v) {
            if (!bad[u][v]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}