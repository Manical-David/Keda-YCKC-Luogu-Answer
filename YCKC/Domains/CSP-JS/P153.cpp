#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 三维坐标结构体
struct Point {
    int l, r, c;  // 层、行、列
    int steps;    // 到达该点的步数
    Point(int l_, int r_, int c_, int s_) : l(l_), r(r_), c(c_), steps(s_) {}
};

// 6个可能的移动方向：上下、左右、前后
int dirs[6][3] = {
    {1, 0, 0},  // 下层
    {-1, 0, 0}, // 上层
    {0, 1, 0},  // 下行
    {0, -1, 0}, // 上行
    {0, 0, 1},  // 右移
    {0, 0, -1}  // 左移
};

char mp[100][100][100];  // 三维迷宫
bool vis[100][100][100];  // 记录是否访问过
int L, R, C;  // 层、行、列

// BFS搜索最短路径
int bfs(int sl, int sr, int sc) {
    queue<Point> q;
    q.push(Point(sl, sr, sc, 0));
    vis[sl][sr][sc] = true;
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        // 检查是否到达终点
        if (mp[cur.l][cur.r][cur.c] == 'E') {
            return cur.steps;
        }
        
        // 尝试6个方向的移动
        for (int i = 0; i < 6; ++i) {
            int nl = cur.l + dirs[i][0];
            int nr = cur.r + dirs[i][1];
            int nc = cur.c + dirs[i][2];
            
            // 检查新位置是否合法：在范围内、不是障碍物、未访问过
            if (nl >= 0 && nl < L && nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (mp[nl][nr][nc] != '#' && !vis[nl][nr][nc]) {
                    vis[nl][nr][nc] = true;
                    q.push(Point(nl, nr, nc, cur.steps + 1));
                }
            }
        }
    }
    
    return -1;
}
int main() {
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) break;
        int sl = -1, sr = -1, sc = -1;
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < R; ++j) {
                cin >> mp[i][j];
                for (int k = 0; k < C; ++k) {
                    if (mp[i][j][k] == 'S') {
                        sl = i;
                        sr = j;
                        sc = k;
                    }
                }
            }
        }
        memset(vis, false, sizeof(vis));
        int ans = bfs(sl, sr, sc);
        if (ans != -1) {
            cout << "Escaped in " << ans << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }
    }
    
    return 0;
}
