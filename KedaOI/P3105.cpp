#include <bits/stdc++.h>
using namespace std;
constexpr int N = 37;
int n, a[N][N];
bool check(int x1, int y1) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            vector<pair<int, int>> path;
            for (int i = 0; i < 5; i++) {
                int xx = x1 + dx * i, yy = y1 + dy * i;
                if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
                if (a[xx][yy] == 0) break;
                path.push_back(make_pair(xx, yy));
            }
            if ((int)path.size() == 5) {
                for (const auto &it : path) {
                    printf("%d %d\n", it.first, it.second);
                }
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                if (check(i, j)) {
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}