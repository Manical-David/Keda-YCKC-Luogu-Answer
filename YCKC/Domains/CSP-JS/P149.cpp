#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 2000;
const int SF = 1300;
int g[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int MDx[] = {0, 1, -1, 0, 0};
int MDy[] = {0, 0, 0, 1, -1};

struct node {
    int x, y, time;
    node(int x_, int y_, int t_) : x(x_), y(y_), time(t_) {}
};

int main() {
    int M;
    cin >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            g[i][j] = INF;
        }
    }
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        for (int d = 0; d < 5; ++d) {
            int nx = x + MDx[d];
            int ny = y + MDy[d];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (t < g[nx][ny]) {
                    g[nx][ny] = t;
                }
            }
        }
    }
    if (g[0][0] <= 0) {
        cout << -1 << '\n';
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(node(0, 0, 0));
    vis[0][0] = true;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int t = cur.time;
        if (g[x][y] == INF) {
            cout << t << '\n';
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nt = t + 1;
            if (nx > SF || ny > SF) {
                cout << nt << '\n';
                return 0;
            }
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (!vis[nx][ny] && nt < g[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push(node(nx, ny, nt));
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
