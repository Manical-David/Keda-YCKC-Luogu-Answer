#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct Edge {
    int to, cost;
};
int main() {
    int N, P, K;
    cin >> N >> P >> K;
    vector<vector<Edge>> g(N + 1);
    int maxL = 0;
    for (int i = 0; i < P; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
        maxL = max(maxL, l);
    }
    int l = 0, r = maxL, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> cnt(N + 1, INF);
        deque<int> dq;
        cnt[1] = 0;
        dq.push_front(1);
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            for (auto &e : g[u]) {
                int v = e.to;
                int add = (e.cost > mid ? 1 : 0);
                if (cnt[v] > cnt[u] + add) {
                    cnt[v] = cnt[u] + add;
                    if (add == 0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
        if (cnt[N] <= K) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}