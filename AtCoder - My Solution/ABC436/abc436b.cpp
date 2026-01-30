#include <bits/stdc++.h>
#define INF -0x3f3f3f
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <vector <int> > a(n, vector <int> (n, INF));
    int k = 1;
    a[0][(n - 1) / 2] = k;
    int r = 0, c = (n - 1) / 2;
    for (int i = 0; i < n * n - 1; i++) {
        int nr = (r - 1 + n) % n;
        int nc = (c + 1) % n;
        if (a[nr][nc] == INF) {
            r = nr;
            c = nc;
        } else {
            r = (r + 1) % n;
        }
        k++;
        a[r][c] = k;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}