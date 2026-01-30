#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSUNext {
    int n;
    vector<int> nxt;
    DSUNext(int n=0): n(n), nxt(n+2) {
        for (int i = 0; i <= n+1; ++i) nxt[i] = i;
    }
    int find(int x) {
        if (x > n+1) return n+1;
        return nxt[x] == x ? x : nxt[x] = find(nxt[x]);
    }
    void remove(int x) {
        nxt[x] = find(x+1);
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    DSUNext dsu(N);
    vector<int> cnt(N+2, 0);
    for (int i = 1; i <= N; ++i) cnt[i] = 1;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        ll count = 0;
        int v = dsu.find(1);
        while (v <= X) {
            if (cnt[v]) {
                count += cnt[v];
                cnt[Y] += cnt[v];
                cnt[v] = 0;
            }
            dsu.remove(v);
            v = dsu.find(v);
        }
        cout << count << '\n';
    }
    return 0;
}