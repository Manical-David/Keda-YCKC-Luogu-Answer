#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<vector<int> > grid(N + 1, vector<int>(M + 1, 0));
    vector<vector<int> > pre(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i][j];
        }
    }

    int max_sum = INT_MIN;
    int ans_x = 1, ans_y = 1;
    for (int i = 1; i <= N - C + 1; ++i) {
        for (int j = 1; j <= M - C + 1; ++j) {
            int x1 = i, y1 = j;
            int x2 = i + C - 1, y2 = j + C - 1;
            int sum = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
            if (sum > max_sum) {
                max_sum = sum;
                ans_x = x1;
                ans_y = y1;
            }
        }
    }
    cout << ans_x << " " << ans_y << endl;
    return 0;
}