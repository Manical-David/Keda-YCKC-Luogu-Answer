#include <bits/stdc++.h>
using namespace std;
const int N = 205;
char mp[N][N];
int dist[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        pair<int, int> S, E;
        for (int i = 0; i < R; ++i) {
            cin >> mp[i];
            for (int j = 0; j < C; ++j) {
                if (mp[i][j] == 'S') S = {i, j};
                if (mp[i][j] == 'E') E = {i, j};
            }
        }
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        q.push(S);
        dist[S.first][S.second] = 0;
        bool fnd = false;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == E.first && y == E.second) {
                fnd = true;
                break;
            }
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                    mp[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        if (dist[E.first][E.second] == -1)
            cout << "oop!" << endl;
        else
            cout << dist[E.first][E.second] << endl;
    }
    return 0;
}