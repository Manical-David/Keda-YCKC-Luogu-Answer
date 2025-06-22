#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> pl(N, vector<bool>(M, false));
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        int row = x - 1;
        int col = y - 1;
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nr = row + dx;
                int nc = col + dy;
                if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                    if (abs(dx) + abs(dy) <= 2) {
                        pl[nr][nc] = true;
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (!pl[r][c]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
