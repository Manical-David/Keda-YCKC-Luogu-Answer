#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<vector<int>>> A(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int z = 1; z <= n; ++z) {
                cin >> A[x][y][z];
            }
        }
    }
    vector<vector<vector<int>>> pre(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int z = 1; z <= n; ++z) {
                pre[x][y][z] = A[x][y][z]
                                + pre[x - 1][y][z]
                                + pre[x][y - 1][z]
                                + pre[x][y][z - 1]
                                - pre[x - 1][y - 1][z]
                                - pre[x - 1][y][z - 1]
                                - pre[x][y - 1][z - 1]
                                + pre[x - 1][y - 1][z - 1];
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        int sum = pre[Rx][Ry][Rz]
                - pre[Lx - 1][Ry][Rz]
                - pre[Rx][Ly - 1][Rz]
                - pre[Rx][Ry][Lz - 1]
                + pre[Lx - 1][Ly - 1][Rz]
                + pre[Lx - 1][Ry][Lz - 1]
                + pre[Rx][Ly - 1][Lz - 1]
                - pre[Lx - 1][Ly - 1][Lz - 1];
        cout << sum << '\n';
    }
    return 0;
}
