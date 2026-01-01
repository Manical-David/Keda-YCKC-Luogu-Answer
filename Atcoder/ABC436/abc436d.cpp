// ...existing code...
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    if (!(cin >> h >> w)) return 0;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];
    vector <vector <int> > dist(h, vector<int> (w, -1));
    vector <vector <pair <int,int> > > pos(26);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c = s[i][j];
            if ('a' <= c && c <= 'z') pos[c - 'a'].push_back({i, j});
        }
    }
    vector <bool> us(26, false);
    deque <pair <int,int> > q;
    dist[0][0] = 0;
    q.emplace_back(0, 0);
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop_front();
        if (r == h - 1 && c == w - 1) break;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (s[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.emplace_back(nr, nc);
        }
        char ch = s[r][c];
        if ('a' <= ch && ch <= 'z') {
            int idx = ch - 'a';
            if (!us[idx]) {
                for (auto &p: pos[idx]) {
                    int rr = p.first, cc = p.second;
                    if (dist[rr][cc] == -1) {
                        dist[rr][cc] = dist[r][c] + 1;
                        q.emplace_back(rr, cc);
                    }
                }
                us[idx] = true;
            }
        }
    }
    cout << dist[h - 1][w - 1] << '\n';
    return 0;
}
// submitted via cph-submit