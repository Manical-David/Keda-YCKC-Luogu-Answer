#include <bits/stdc++.h>
using namespace std;
constexpr int N = 507;
constexpr int dir[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}},
              iir[4][2] = {{-1, -1}, {-1, 0}, {0, 0}, {0, -1}};
string cs = R"(\/\/)";
int n, m;
char g[N][N];
struct node {
    int x, y;
};
int dist[N][N];
bool st[N][N];
int bfs() {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    deque<node> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;
    while (!dq.empty()) {
        node t = dq.front();
        dq.pop_front();
        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        for (int i = 0; i < 4; i++) {
            int xx = t.x + dir[i][0], yy = t.y + dir[i][1];
            if (xx < 0 || xx > n || yy < 0 || yy > m) continue;
            int ca = t.x + iir[i][0], cb = t.y + iir[i][1];
            int d = dist[t.x][t.y] + (g[ca][cb] != cs[i]);
            if (d < dist[xx][yy]) {
                dist[xx][yy] = d;
                if (g[ca][cb] != cs[i]) {
                    dq.push_back({xx, yy});
                } else {
                    dq.push_front({xx, yy});
                }
            }
        }
    }
    return dist[n][m];
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    int t = bfs();
    if (t == 0x3f3f3f3f) {
        printf("NO SOLUTION\n");
    } else {
        printf("%d\n", t);
    }
    return 0;
}