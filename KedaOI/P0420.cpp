#include <bits/stdc++.h>
using namespace std;
constexpr int N = 47, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char g[N][N];
bool st[N][N];
struct node {
    int x, y, step;
};
int bfs() {
    node start = {1, 1, 1};
    queue <node> q;
    q.push(start);
    st[start.x][start.y] = true;
    while(!q.empty()) {
        node t = q.front();
        q.pop();
        if(t.x == n && t.y == m) return t.step;
        st[t.x][t.y] = true;
        for(int i = 0; i < 4; i++) {
            int xx = t.x + dir[i][0], yy = t.y + dir[i][1], step = t.step + 1;
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(g[xx][yy] == '#' || st[xx][yy]) continue;
            q.push({xx, yy, step});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
    }
    cout << bfs() << '\n';
    return 0;
}