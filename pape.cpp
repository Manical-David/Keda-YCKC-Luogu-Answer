#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100010;
long long n, m, len, V, l[N], r[N], d[N], v[N], a[N], p[N], ans1, ans2, T;
int V2;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
int f(int v0, int a, int s) {
    return v0 * v0 + 2 * a * s;
}
void solve() {
    ans1 = ans2 = 0;
    while (!q.empty()) q.pop();
    cin >> n >> m >> len >> V;
    V2 = V;
    V2 *= V;
    for (long long i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for (long long i = 1; i <= m; i++) cin >> p[i];
    for (long long i = 1; i <= n; i++) {
        if (a[i] == 0) {
            long long L = 1, R = m;
            while (L < R) {
                long long Mid = (L + R) / 2;
                if (p[Mid] < d[i]) L = Mid + 1;
                else R = Mid;
            }
            if (p[L] < d[i] || v[i] <= V) {
                l[i] = r[i] = -1;
                continue;
            }
            l[i] = L;
            r[i] = m;
        } else if (a[i] < 0) {
            long long L = d[i], R = len;
            while (L < R) {
                long long Mid = (L + R + 1) / 2;
                if (f(v[i], a[i], Mid - d[i]) <= V2) R = Mid - 1;
                else L = Mid;
            }
            if (f(v[i], a[i], L - d[i]) <= V2) {
                l[i] = r[i] = -1;
                continue;
            }
            long long ansr = L, ansl = d[i];
            L = 1, R = m;
            while (L < R) {
                long long Mid = (L + R) / 2;
                if (p[Mid] < ansl) L = Mid + 1;
                else R = Mid;
            }
            if (p[L] < ansl || p[L] > ansr) {
                l[i] = r[i] = -1;
                continue;
            }
            l[i] = L;
            L = 1, R = m;
            while (L < R) {
                long long Mid = (L + R + 1) / 2;
                if (p[Mid] > ansr) R = Mid - 1;
                else L = Mid;
            }
            r[i] = L;
        } else {
            long long L = d[i], R = len;
            while (L < R) {
                long long Mid = (L + R) / 2;
                if (f(v[i], a[i], Mid - d[i]) <= V2) L = Mid + 1;
                else R = Mid;
            }
            if (f(v[i], a[i], L - d[i]) <= V2) {
                l[i] = r[i] = -1;
                continue;
            }
            long long ansl = L, ansr = len;
            L = 1, R = m;
            while (L < R) {
                long long Mid = (L + R) / 2;
                if (p[Mid] < ansl) L = Mid + 1;
                else R = Mid;
            }
            if (p[L] < ansl || p[L] > ansr) {
                l[i] = r[i] = -1;
                continue;
            }
            l[i] = L;
            L = 1, R = m;
            while (L < R) {
                long long Mid = (L + R + 1) / 2;
                if (p[Mid] > ansr) R = Mid - 1;
                else L = Mid;
            }
            r[i] = L;
        }
    }
    for (long long i = 1; i <= n; i++)
        if (l[i] != -1)
            q.push({r[i], l[i]}), ans1++;
    long long nr = -1;
    while (!q.empty()) {
        pair<long long, long long> now = q.top();
        q.pop();
        if (nr < now.second)
            nr = now.first, ans2++;
    }
    cout << ans1 << ' ' << m - ans2 << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}