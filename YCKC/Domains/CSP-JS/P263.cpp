#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < a; ++i) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = 0;
        q.push({x, y});
    }
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dis[nx][ny] == -1) {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < b; ++i) {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] << '\n';
    }
    return 0;
}