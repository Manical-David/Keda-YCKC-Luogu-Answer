#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3;
struct node {
    int x;
    int y;
    int dis;
};
int vis[N][N], cnt = 0, disy[N][N], dism[N][N];
int n, m;
char s[N][N];
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
int x_y, y_y, x_m, y_m;
int yj = 0;
void bfsy() {
    queue<node> q;
    node now;
    now.x = x_y;
    now.y = y_y;
    now.dis = 0;
    q.push(now);
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (disy[now.x][now.y] != -1)
            continue;
        disy[now.x][now.y] = now.dis;
        node cnt;
        for (int i = 0; i < 4; i++) {
            cnt.x = now.x + X[i];
            cnt.y = now.y + Y[i];
            cnt.dis = now.dis + 1;
            if (cnt.x < 1 || cnt.x > n || cnt.y < 1 || cnt.y > m)
                continue;
            if (s[cnt.x][cnt.y] == '#')
                continue;
            q.push(cnt);
        }
    }
}
int ans;
void bfsm() {
    queue<node> q;
    node now;
    now.x = x_m;
    now.y = y_m;
    now.dis = 0;
    q.push(now);
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (dism[now.x][now.y] != -1)
            continue;
        if (s[now.x][now.y] == '@') {
            ans = min(ans, disy[now.x][now.y] + now.dis);
        }
        dism[now.x][now.y] = now.dis;
        node cnt;
        for (int i = 0; i < 4; i++) {
            cnt.x = now.x + X[i];
            cnt.y = now.y + Y[i];
            cnt.dis = now.dis + 1;
            if (cnt.x < 1 || cnt.x > n || cnt.y < 1 || cnt.y > m)
                continue;
            if (s[cnt.x][cnt.y] == '#')
                continue;
            q.push(cnt);
        }
    }
}
signed main() {
    int t;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ans = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                disy[i][j] = dism[i][j] = -1;
            }
        }
        for (int i = 1; i <= n; i++) {

            cin >> s[i] + 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == 'Y') {
                    x_y = i;
                    y_y = j;
                }
                if (s[i][j] == 'M') {
                    x_m = i;
                    y_m = j;
                }
            }
        }
        bfsy();
        bfsm();
        cout << ans * 11 << '\n';
    }
    return 0;
}