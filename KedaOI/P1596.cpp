#include <bits/stdc++.h>
using namespace std;
constexpr int N = 101;
int mp[N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        mp[x][y]++;
    }
    for(int i = 1; i <= n; i++, cout << '\n') {
        for(int j = 1; j <= n; j++) {
            cout << mp[i][j] << ' ';
        }
    }
    return 0;
}