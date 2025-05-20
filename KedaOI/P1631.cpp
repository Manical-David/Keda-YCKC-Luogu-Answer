#include <iostream>
using namespace std;
const int N = 1010;
int a[N][N];        // 地图
bool vis[N][N];     // 是否访问过
int n, m;           // 地图大小
int lu, yan;        // 当前岛屿陆地数量 & 临海陆地数量
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y) {
    vis[x][y] = true;
    lu++;
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (a[nx][ny] == 0) {
            flag = true;
            continue;
        }
        if (!vis[nx][ny] && a[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
    if (flag) yan++; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1 && !vis[i][j]) {
                lu = 0, yan = 0;
                dfs(i, j);
                if (lu == yan) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}