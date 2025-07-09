#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct state {
    int u;
    bool car;
    ll cost;
    bool operator>(const state& rhs) const {
        return cost > rhs.cost;
    }
};
int main() {
    int n, A, B, C;
    cin >> n >> A >> B >> C;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    priority_queue<state, vector<state>, greater<state>> pq;
    dist[1][0] = 0;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int u = cur.u, car = cur.car;
        ll cost = cur.cost;
        if (cost > dist[u][car]) continue;
        for (int v = 1; v <= n; ++v) {
            if (v == u) continue;
            if (car == 0) {
                ll ncost = cost + 1LL * a[u][v] * A;
                if (ncost < dist[v][0]) {
                    dist[v][0] = ncost;
                    pq.push({v, 0, ncost});
                }
                ncost = cost + 1LL * a[u][v] * B + C;
                if (ncost < dist[v][1]) {
                    dist[v][1] = ncost;
                    pq.push({v, 1, ncost});
                }
            } else {
                ll ncost = cost + 1LL * a[u][v] * B + C;
                if (ncost < dist[v][1]) {
                    dist[v][1] = ncost;
                    pq.push({v, 1, ncost});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << endl;
    return 0;
}