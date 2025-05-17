// 别问我为什么用那么多assign，我也是被逼的
#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<vector<int>> a, time_, maxn;
vector<vector<vector<int>>> memo;
vector<vector<bool>> nums;
int ans = 0;
int dx[2] = {0, 1}, dy[2] = {1, 0};
void build(){
    maxn.assign(n + 2, vector<int>(m + 2, 0));
    for(int i = n; i >= 1; --i){
        for(int j = m; j >= 1; --j){
            int mx = 0;
            if(i < n) mx = max(mx, maxn[i+1][j]);
            if(j < m) mx = max(mx, maxn[i][j+1]);
            maxn[i][j] = a[i][j] + mx; // 小用DP
        }
    }
}
void dfs(int x, int y, int step, int tong){
    // 合法性
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(time_[x][y] <= step) return; // 剪枝
    tong += a[x][y];
    ans = max(ans, tong);
    if(tong + maxn[x][y] <= ans) return; // 剪枝：太小了
    if(memo[x][y][step] >= tong) return; // 记忆化
    memo[x][y][step] = tong;
    nums[x][y] = true;
    for(int dir = 0; dir < 2; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !nums[nx][ny]){
            if(time_[nx][ny] > step + 1){
                dfs(nx, ny, step + 1, tong);
            }
        }
    }
    nums[x][y] = false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a.assign(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];

    cin >> t;
    time_.assign(n + 1, vector<int>(m + 1, INT_MAX));
    for(int i = 0; i < t; ++i){
        int x, y, v;
        cin >> x >> y >> v;
        time_[x][y] = v;
    }
    build();
    nums.assign(n + 1, vector<bool>(m + 1, false));
    int maxx = n + m;
    memo.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(maxx + 1, -1))); // 双环
    dfs(1, 1, 0, 0);
    cout << ans << "\n";
    return 0;
}
