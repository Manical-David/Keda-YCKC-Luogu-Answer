#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 1010;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Node {
    int x, y, cost;
    bool operator>(const Node& rhs) const {
        return cost > rhs.cost;
    }
};

int main() {
    int N, sx, sy;
    cin >> N >> sx >> sy;
    vector<vector<bool>> hay(MAX, vector<bool>(MAX, false));
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        hay[x][y] = true;
    }
    vector<vector<int>> dist(MAX, vector<int>(MAX, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[sx][sy] = 0;
    pq.push({sx, sy, 0});
    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, cost = cur.cost;
        if (cost > dist[x][y]) continue;
        if (x == 0 && y == 0) {
            cout << cost << endl;
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            int ncost = cost + (hay[nx][ny] ? 1 : 0);
            if (dist[nx][ny] > ncost) {
                dist[nx][ny] = ncost;
                pq.push({nx, ny, ncost});
            }
        }
    }
    return 0;
}