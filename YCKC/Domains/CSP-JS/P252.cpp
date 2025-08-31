#include <bits/stdc++.h>
using namespace std;
constexpr int N = 60;
int n, m;
int g[N][N];
int sx, sy, ex, ey;
int ans = 0;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
void bfs() {
    ex = m, ey = n;
    queue <pair <int, int> > q;
    q.push({sx, sy});
    while(!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        ans++;
        for(int i = 0; i < 4; i++) { // record steps arrow value
            if(nx + dx[i] < ex && nx + dx[i] >= 0 && ny + dy[i] < ey && ny + dy[i] >= 0) {
                q.push({nx + dx[i], ny + dy[i]});
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    bfs();
    return 0;
}