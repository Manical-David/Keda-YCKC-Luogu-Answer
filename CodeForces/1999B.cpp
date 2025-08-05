#include <bits/stdc++.h>
using namespace std;
int b[10001][5];
int x(int q, int w, int e, int r)
{
    int sum = 0, c[5] = {0, q, w, e, r}, n = 0, m = 0;
    if (c[1] > c[3]) n++;
    if (c[1] < c[3]) m++;
    if (c[2] > c[4]) n++;
    if (c[2] < c[4]) m++;
    if (n > m) sum++;
    n = 0, m = 0;
    if (c[2] > c[3]) n++;
    if (c[2] < c[3]) m++;
    if (c[1] > c[4]) n++;
    if (c[1] < c[4]) m++;
    if (n > m) sum++;
    n = 0, m = 0;
    if (c[1] > c[4]) n++;
    if (c[1] < c[4]) m++;
    if (c[2] > c[3]) n++;
    if (c[2] < c[3]) m++;
    if (n > m) sum++;
    n = 0, m = 0;
    if (c[2] > c[4]) n++;
    if (c[2] < c[4]) m++;
    if (c[1] > c[3]) n++;
    if (c[1] < c[3]) m++;
    if (n > m) sum++;
    n = 0, m = 0;
    return sum;
}
int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
        for (int l = 1; l <= 4; l++)
            cin >> b[i][l];
    for (int i = 1; i <= a; i++) {
        cout << x(b[i][1], b[i][2], b[i][3], b[i][4]) << endl;
    }
    return 0;
}