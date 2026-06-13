#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200005;
ll a[MAXN], bit[MAXN];
inline int lowbit(int x) { return x & -x; }
void add(int i, ll delta) {
    for (; i <= MAXN - 1; i += lowbit(i)) {
        bit[i] += delta;
    }
}
ll qin(int i) {
    ll res = 0;
    for (; i > 0; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}
ll ar_(int L, int R) {
    return qin(R) - qin(L - 1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        add(i + 1, a[i]);
    }
    for (int i = 0; i < Q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int L, R;
            cin >> L >> R;
            cout << ar_(L, R) << '\n';
        } else {
            int x;
            ll v;
            cin >> x >> v;
            add(x, v - a[x - 1]);
            a[x - 1] = v;
        }
    }
    return 0;
}