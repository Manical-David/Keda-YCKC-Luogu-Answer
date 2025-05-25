#include <bits/stdc++.h>
using namespace std;
int M, N, startX, startY;
vector<string> grid;
vector<vector<bool>> vis;
int dx[4] = {-1, 1, 0, 0}; // 上下左右
int dy[4] = {0, 0, -1, 1};
bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}
int bfs(int x, int y) {
    int tong = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (!check(nx, ny) || grid[nx][ny] == '.') {
                tong++;
            } else if (!vis[nx][ny] && grid[nx][ny] == 'X') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return tong;
}
int main() {
    cin >> M >> N >> startX >> startY;
    startX--;
    startY--;
    grid.resize(M);
    vis.assign(M, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        cin >> grid[i];
    }
    cout << bfs(startX, startY) << endl;
    return 0;
}