#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char maze[N][N];
int dist[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> S, T;
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') S = {i, j};
            if (maze[i][j] == 'T') T = {i, j};
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(S);
    dist[S.first][S.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == T.first && y == T.second) break;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                maze[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[T.first][T.second] << endl;
    return 0;
}