#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<string> grid;
int cnt;
int W, H;
void dfs(int x, int y) {
    grid[y][x] = '#';
    cnt++;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] == '.') {
            dfs(nx, ny);
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> W >> H;
        grid.resize(H);
        int x, y;
        for (int i = 0; i < H; ++i) {
            cin >> grid[i];
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] == '@') {
                    x = j;
                    y = i;
                    grid[i][j] = '.';
                }
            }
        }
        cnt = 0;
        dfs(x, y);
        cout << cnt << endl;
    }
    return 0;
}