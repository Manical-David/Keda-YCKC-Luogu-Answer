#include <bits/stdc++.h>
using namespace std;
constexpr int N = 17, dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int g[N][N];
bool st[N][N];
struct node {
    int x, y;
};
void bfs(int x, int y) {
    node start = {x, y};
    queue <node> q;
    q.push(start);
    st[x][y] = true;
    while(!q.empty()) {
        node t = q.front();
        q.pop();
        st[t.x][t.y] = true;
        for(int i = 0; i < 4; i++) {
            int xx = t.x + dir[i][0], yy = t.y + dir[i][1];
            if(xx < 0 || xx > 11 || yy < 0 || yy > 11) continue;
            if(st[xx][yy]) continue;
            q.push({xx, yy});
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            cin >> g[i][j];
            if(g[i][j] == 1) st[i][j] = true;
        }
    }
    bfs(0, 0);
    int res = 0;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(st[i][j] == false) res += 1;
        }
    }
    cout << res << '\n';
    return 0;
}