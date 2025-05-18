#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node {
    int x, y;
};
char g[N][N];
int dist[N][N];
int n, m;
void bfs() {
    memset(dist, -1, sizeof(dist));
    queue <node> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '1') {
                dist[i][j] = 0;
                q.push({i, j});
                
            }
        }
    }
    while(!q.empty()) {
        node t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = t.x + dir[i][0], yy = t.y + dir[i][1];
            if(xx < 0 || xx > n || yy < 0 || yy > m) continue;
            if(dist[xx][yy] != -1) continue;
            dist[xx][yy] = dist[t.x][t.y] + 1;
            q.push({xx, yy});
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    bfs();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d%c", dist[i][j], " \n"[j == m - 1]);
        }
    }
    return 0;
}