#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100;
constexpr int M = 100;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
char g[N][M]; 
int vis[N][M]; 
struct node {
    int x, y;
    node(int x_, int y_) : x(x_), y(y_) {}
};
int main() {
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1; 
    int ex = -1, ey = -1; 
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S') {
                sx = i;
                sy = j;
            } 
            else if (g[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }
    memset(vis, -1, sizeof(vis)); 
    queue<node> q;
    q.push(node(sx, sy)); 
    vis[sx][sy] = 0;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        if (cur.x == ex && cur.y == ey) { 
            cout << vis[cur.x][cur.y] << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) { 
            int nx = cur.x + dirs[i][0];
            int ny = cur.y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && vis[nx][ny] == -1) { 
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
                q.push(node(nx, ny));
            }
        }
    }
    cout << -1 << '\n'; 
    return 0;
}