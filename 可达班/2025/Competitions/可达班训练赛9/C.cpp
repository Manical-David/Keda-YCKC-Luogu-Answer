#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct state {
    int x, y, k;
    state(int x, int y, int k) : x(x), y(y), k(k) {}
};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    vector<vector<int>> min_k(N, vector<int>(M, INF));
    queue<state> q;
    q.emplace(0, 0, 0);
    min_k[0][0] = 0;
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int k = cur.k;
        if (x == N - 1 && y == M - 1) {
            cout << k << endl;
            return 0;
        }
        if (k > min_k[x][y]) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (grid[nx][ny] == '.') {
                if (k < min_k[nx][ny]) {
                    min_k[nx][ny] = k;
                    q.emplace(nx, ny, k);
                }
            } else {
                bool flag = false;
                for (int a = -1; a <= 0; ++a) {
                    for (int b = -1; b <= 0; ++b) {
                        int tx = nx + a;
                        int ty = ny + b;
                        if (tx >= 0 && ty >= 0 && tx + 1 < N && ty + 1 < M) {
                            bool bl = true;
                            for (int c = 0; c < 2; ++c) {
                                for (int d = 0; d < 2; ++d) {
                                    if (grid[tx + c][ty + d] != '#') {
                                        bl = false;
                                        break;
                                    }
                                }
                                if (!bl) break;
                            }
                            if (bl) {
                                int new_k = k + 1;
                                if (new_k < min_k[nx][ny]) {
                                    min_k[nx][ny] = new_k;
                                    q.emplace(nx, ny, new_k);
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}