#include <bits/stdc++.h>
using namespace std;
constexpr int dir[8][2] = {
    {1, 2}, 
    {2, 1}, 
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1}, 
    {-1, 2}
};
constexpr int N = 17;
int n, m, res = 0;
bool st[N][N];
void dfs(int x, int y, int cnt) {
    if(cnt == n * m) {
        res += 1;
        return ;
    }
    st[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(st[xx][yy]) continue;
        dfs(xx, yy, cnt + 1);
    }
    st[x][y] = false;
    
}
void solve() {
    memset(st, false, sizeof(st));
    int x, y;
    cin >> n >> m >> x >> y;
    res = 0;
    dfs(x, y, 1);
    cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}