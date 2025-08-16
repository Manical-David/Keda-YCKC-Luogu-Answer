#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M;
    ll D;
    cin >> N >> M >> D;
    vector<ll> a(N), b(M);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll maxx = -1;
    for (ll a : a) {
        ll lower = a - D;
        ll upper = a + D;
        auto l = lower_bound(b.begin(), b.end(), lower);
        auto r = upper_bound(b.begin(), b.end(), upper);
        if (l != r) {
            ll best = *(prev(r));
            maxx = max(maxx, a + best);
        }
    }
    cout << maxx << '\n';
    return 0;
}
