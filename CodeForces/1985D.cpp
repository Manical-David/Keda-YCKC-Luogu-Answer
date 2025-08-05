#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    char ch;
    cin >> n >> m;
    int x = 0, y = 0, maxx = 0, s = 0, e = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        e = 0, s = 0;
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == '#') {
                if (cnt == 0) s = j;
                cnt++;
                e = j;
            }
        }
        if (cnt > maxx) {
            maxx = cnt;
            x = i;
            y = (e + s) / 2; // O·
        }
    }
    cout << x + 1 << " " << y + 1 << endl; // 0<-
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}