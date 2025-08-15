#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N + 1, vector<int>(M + 1, 0)), pre1(N + 1, vector<int>(M + 1, 0)), pre2(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> a[i][j];
            pre1[i][j] = pre1[i - 1][j] + pre1[i][j - 1] - pre1[i - 1][j - 1] + (a[i][j] == 0);
            pre2[i][j] = pre2[i - 1][j] + pre2[i][j - 1] - pre2[i - 1][j - 1] + (a[i][j] == 1);
        }
    }
    int cnt = 0;
    int maxx = min(N, M);
    for (int K = 2; K <= maxx; ++K) {
        for (int i = 1; i + K - 1 <= N; ++i) {
            for (int j = 1; j + K - 1 <= M; ++j) {
                int x1 = i, y1 = j;
                int x2 = i + K - 1, y2 = j + K - 1;
                int cnt0 = pre1[x2][y2] - pre1[x1 - 1][y2] - pre1[x2][y1 - 1] + pre1[x1 - 1][y1 - 1];
                int cnt1 = pre2[x2][y2] - pre2[x1 - 1][y2] - pre2[x2][y1 - 1] + pre2[x1 - 1][y1 - 1];
                if (abs(cnt0 - cnt1) <= 1) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
