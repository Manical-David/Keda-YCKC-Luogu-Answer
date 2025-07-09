#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;
    double rate;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        double rate = 1.0 - z / 100.0;
        g[x].push_back({y, rate});
        g[y].push_back({x, rate});
    }
    int A, B;
    cin >> A >> B;
    vector<double> cost(n + 1, 1e18);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    cost[B] = 100.0;
    pq.push({100.0, B});
    while (!pq.empty()) {
        auto [cur, u] = pq.top(); pq.pop();
        if (cur > cost[u] + 1e-9) continue;
        for (auto &e : g[u]) {
            double need = cur / e.rate;
            if (need < cost[e.to] - 1e-8) {
                cost[e.to] = need;
                pq.push({need, e.to});
            }
        }
    }
    cout << fixed << setprecision(8) << cost[A] << endl;
    return 0;
}