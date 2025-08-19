#include <bits/stdc++.h>
using namespace std;
int sum[50000][2];
int ax, ay, bx, by, k, pd;
int cx[4] = {0, -1, 0, 1};
int cy[4] = {-1, 0, 1, 0};
bool temp[17][17];
int g[17][17];
void print() {
    if (pd == 0) {
        pd = 1;
    }
    for (int h = 0; h <= k - 1; h++)
        cout << "(" << sum[h][0] << "," << sum[h][1] << ")" << "->";
    cout << "(" << bx << "," << by << ")" << '\n';
}
void walk(int x, int y) {
    if (x == bx && y == by) {
        print();
        return;
    }
    else {
        for (int i = 0; i <= 3; i++)
            if (g[x + cx[i]][y + cy[i]] == 1 && temp[x + cx[i]][y + cy[i]] == 0) {
                temp[x][y] = 1;
                sum[k][0] = x;
                sum[k][1] = y;
                k++;
                walk(x + cx[i], y + cy[i]);
                temp[x][y] = 0;
                k--;
            }
    }
}
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    cin >> ax >> ay;
    cin >> bx >> by;
    walk(ax, ay);
    if (pd == 0)
        cout << "-1";
    return 0;
}
