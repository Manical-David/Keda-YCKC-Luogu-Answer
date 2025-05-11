#include <bits/stdc++.h>
using namespace std;
constexpr int N = 17, dir[2][2] = {{1, 0}, {0, 1}};
int n, m, g[N][N];
set<int> st;
int res = 0;
void dfs(int x, int y) {
    if(x == n && y == m) {
        res += 1;
        return ;
    }
    for(int i = 0; i < 2; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if(xx < 1 || x > n || yy < 1 || yy > m) continue;
        if(st.count(g[xx][yy])) continue;
        st.insert(g[xx][yy]);
        dfs(xx, yy);
        st.erase(g[xx][yy]);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    st.insert(g[1][1]);
    dfs(1, 1);
    cout << res << '\n';
    return 0;
}