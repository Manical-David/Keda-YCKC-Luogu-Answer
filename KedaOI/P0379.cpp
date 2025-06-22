#include <bits/stdc++.h>
using namespace std;
const int N = 22;
char mp[N][N];
int dist[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int M, N;
    while (cin >> M >> N, M && N) {
        int sx = -1, sy = -1;
        for (int i = 0; i < M; ++i) {
            cin >> mp[i];
            for (int j = 0; j < N; ++j) {
                if (mp[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }
        memset(dist, -1, sizeof(dist));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0; // 步数从0开始
        int ans = -1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
            if (mp[x][y] == '*') {
                ans = dist[x][y];
                break;
            }
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
                    mp[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}