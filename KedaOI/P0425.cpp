#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int main() {
    int n;
    cin >> n;
    while (n--) {
        int L;
        cin >> L;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if (sx == ex && sy == ey) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> dist(L, vector<int>(L, -1));
        queue<pair<int, int>> q;
        dist[sx][sy] = 0;
        q.push({sx, sy});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 8; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < L && ny >= 0 && ny < L && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (nx == ex && ny == ey) {
                        cout << dist[nx][ny] << endl;
                        goto next_case;
                    }
                    q.push({nx, ny});
                }
            }
        }
        cout << dist[ex][ey] << endl;
    next_case:;
    }
    return 0;
}