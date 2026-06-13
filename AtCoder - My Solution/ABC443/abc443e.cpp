#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, C;
    cin >> N >> C;
    C--;
    vector<string> g(N);
    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }
    vector<vector<int>> walls(N);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (g[r][c] == '#') walls[c].push_back(r);
        }
    }
    vector <vector <bool> > vis(N, vector <bool> (N, false));
    vis[N-1][C] = true;
    queue<pair<int, int>> q;
    q.push({N - 1, C});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int dc = -1; dc <= 1; dc++) {
            int nc = c + dc;
            if (nc < 0 || nc >= N) continue;
            int nr = r - 1;
            if (nr < 0) continue;
            if (g[nr][nc] == '.') {
                if (!vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            } 
            else {
                if (!walls[nc].empty() && walls[nc].back() == nr) {
                    walls[nc].pop_back();
                    g[nr][nc] = '.';
                    if (!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    string ans(N, '0');
    for (int i = 0; i < N; i++) {
        if (vis[0][i]) {
            ans[i] = '1';
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}