#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct state {
    int diff, type; // type: 0-数学, 1-信息学
    int cost;
    bool operator>(const state& rhs) const {
        return cost > rhs.cost;
    }
};
int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<vector<int>> dist(101, vector<int>(2, INF));
    priority_queue<state, vector<state>, greater<state>> pq;
    dist[a][0] = 0;
    pq.push({a, 0, 0});
    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int d = cur.diff, t = cur.type, cost = cur.cost;
        if (cost > dist[d][t]) continue;
        if (d == b && t == 1) {
            cout << cost << endl;
            return 0;
        }
        if (t == 0) {
            if (cost + x < dist[d][1]) {
                dist[d][1] = cost + x;
                pq.push({d, 1, cost + x});
            }
            if (d > 1 && cost + x < dist[d - 1][1]) {
                dist[d - 1][1] = cost + x;
                pq.push({d - 1, 1, cost + x});
            }
        }
        if (t == 1) {
            if (cost + x < dist[d][0]) {
                dist[d][0] = cost + x;
                pq.push({d, 0, cost + x});
            }
            if (d < 100 && cost + x < dist[d + 1][0]) {
                dist[d + 1][0] = cost + x;
                pq.push({d + 1, 0, cost + x});
            }
        }
        for (int k = 1; k <= 100; ++k) {
            if (d + k <= 100 && cost + k * y < dist[d + k][t]) {
                dist[d + k][t] = cost + k * y;
                pq.push({d + k, t, cost + k * y});
            }
            if (d - k >= 1 && cost + k * y < dist[d - k][t]) {
                dist[d - k][t] = cost + k * y;
                pq.push({d - k, t, cost + k * y});
            }
        }
    }
    return 0;
}