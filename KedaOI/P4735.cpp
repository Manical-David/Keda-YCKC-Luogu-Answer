#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<bitset<N>> mat;
bitset<N> b[N]; // 系数
int n, m;
int gg(int v) {
    int row = 0;
    for (int cl = 0; cl < v; ++cl) {
        int pv = -1;
        for (int i = row; i < m; ++i) {
            if (b[i][cl]) {
                pv = i;
                break;
            }
        }
        if (pv == -1) continue;
        swap(b[row], b[pv]);
        for (int i = 0; i < m; ++i) {
            if (i != row && b[i][cl]) {
                b[i] ^= b[row];
            }
        }
        row++;
    }
    return row; // rank
}
int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        b[i].reset();
        b[i][x] = 1;
        b[i][y] = 1;
        b[i][n] = z % 2; // 常数项放 n 位
    }
    int rank = gg(n);
    cout << n - rank << '\n';
    return 0;
}
