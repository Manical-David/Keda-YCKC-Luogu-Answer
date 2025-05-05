#include <bits/stdc++.h>
using namespace std;
constexpr int N = 9, M = 1 << N;
int one[M], mp[M];
int col[N], row[N], cell[3][3];
char str[100];
int lowbit(int x) {
    return (x & -x);
}
int get(int i, int j) {
    return (row[i] & col[j] & cell[i / 3][j / 3]);
}
void init() {
    for(int i = 0; i < N; i++) {
        row[i] = col[i] = (1 << N) - 1;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cell[i][j] = (1 << N) - 1;
        }
    }
}
void draw(int x, int y, int t, bool is_set) {
    if(is_set) {
        str[x * N + y] = '1' + t;
    }
    else  {
        str[x * N + y] = '.';
    }
    int v = 1 << t;
    if(!is_set) v = -v;
    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}
bool dfs(int cnt) {
    if(cnt == 0) return true;
    int minn = 10, x, y;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(str[i * N + j] == '.') {
                int state = get(i, j);
                if(one[state] < minn) {
                    minn = one[state];
                    x = i, y = j;
                }
            }
        }
    }
    int state = get(x, y);
    for(int i = state; i; i -= lowbit(i)) {
        int t = mp[lowbit(i)];
        draw(x, y, t, true);
        if(dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    for(int i = 0; i < N; i++) {
        mp[1 << i] = i;
    }
    for(int i = 0; i < (1 << N); i++) {
        for(int j = 0; j < N; j++) {
            one[i] += (i >> j & 1);
        }
    }
    while(cin >> str) {
        if(str[0] == 'e') break;
        init();
        int cnt = 0;
        for(int i = 0, k = 0; i < N; i++) {
            for(int j = 0; j < N; j++, k++) {
                if(str[k] != '.') {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else {
                    cnt += 1;
                }
            }
        }
        dfs(cnt);
        puts(str);
    }
    return 0;
}