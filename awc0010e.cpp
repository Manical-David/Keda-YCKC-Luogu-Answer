#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    long long K;
    cin >> N >> K;
    vector<vector<ll> > C(N, vector<ll>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> C[i][j];
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    ll ans = 0;
    do {
        vector<char> vis(N, 0);
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (vis[i]) continue;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                cur = p[cur];
            }
            ++cnt;
        }
        int mins = N - cnt;
        if (mins <= K) {
            ll sum = 0;
            for (int i = 0; i < N; ++i) {
                sum += C[p[i]][p[(i + 1) % N]];
            }
            ans = max(ans, sum);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
    return 0;
}