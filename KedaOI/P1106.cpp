#include <bits/stdc++.h>
using namespace std;
const int N = 5;
int mp[N][N];
bool vis[N][N];
pair<int, int> pre[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void con_output(pair<int, int> p) {
    if (p.first != 0 || p.second != 0)
        con_output(pre[p.first][p.second]);
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}
int main() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mp[i][j];
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == N - 1 && y == N - 1) break;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                !vis[nx][ny] && mp[nx][ny] == 0) {
                vis[nx][ny] = true;
                pre[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    con_output({N - 1, N - 1});
    return 0;
}