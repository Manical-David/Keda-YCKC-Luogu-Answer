#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_R = 113;
constexpr int MAX_C = 77;
int r, c;
char g[MAX_R][MAX_C];
bool vis[MAX_R][MAX_C];
vector<pair<int, int>> path;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool dfs(int x, int y) {
    if (x == r && y == c) {
        path.push_back({x, y});
        return true;
    }
    vis[x][y] = true;
    path.push_back({x, y});
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && !vis[nx][ny] && g[nx][ny] == '.') {
            if (dfs(nx, ny)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}
int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> g[i][j];
        }
    }
    dfs(1, 1);
    for (auto it : path) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}
