#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 8; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << left << setw(5) << dist[i][j];
        }
        cout << endl;
    }
    return 0;
}