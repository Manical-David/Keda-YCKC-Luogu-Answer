#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, c;
    int st;
    node(int l_, int r_, int c_, int s_) : l(l_), r(r_), c(c_), st(s_) {}
};
int dirs[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
char maze[100][100][100];
bool vis[100][100][100];
int L, R, C;
int sl, sr, sc;
int el, er, ec;
int bfs() {
    queue<node> q;
    q.push(node(sl, sr, sc, 0));
    vis[sl][sr][sc] = true;
    
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (p.l == el && p.r == er && p.c == ec) {
            return p.st;
        }
        for (int i = 0; i < 6; i++) {
            int nl = p.l + dirs[i][0];
            int nr = p.r + dirs[i][1];
            int nc = p.c + dirs[i][2];
            if (nl >= 0 && nl < L && nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (!vis[nl][nr][nc] && maze[nl][nr][nc] != '#') {
                    vis[nl][nr][nc] = true;
                    q.push(node(nl, nr, nc, p.st + 1));
                }
            }
        }
    }
    return -1;
}
int main() {
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) break;
        memset(vis, false, sizeof(vis));
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                cin >> maze[l][r];
                for (int c = 0; c < C; c++) {
                    if (maze[l][r][c] == 'S') {
                        sl = l;
                        sr = r;
                        sc = c;
                    } else if (maze[l][r][c] == 'E') {
                        el = l;
                        er = r;
                        ec = c;
                    }
                }
            }
        }
        int ans = bfs();
        if (ans != -1) {
            cout << "Escaped in " << ans << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
    }
    
    return 0;
}
