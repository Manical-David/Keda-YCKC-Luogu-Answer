#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue <pair <ll, int> > pq;
    vector<int> f(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> d[i];
        if (f[i] > 0) {
            pq.push({f[i], i});
        }
    }
    ll ans = 0;
    vector<int> cnt(n, 0);
    for (int i = 0; i < m && !pq.empty(); i++) {
        auto [val, idx] = pq.top();
        pq.pop();
        ans += val;
        cnt[idx]++;
        ll nxt = f[idx] - (ll)cnt[idx] * d[idx];
        if (nxt > 0) {
            pq.push({nxt, idx});
        }
    }
    cout << ans << '\n';
    return 0;
}