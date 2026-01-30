#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<int> next(q + 1);
    next[0] = -1;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            next[i] = next[x];
            next[x] = i;
        } else {
            int x, y;
            cin >> x >> y;
            int cx = x, cy = y;
            long long sx = 0, sy = 0;
            while (true) {
                if (next[cx] != -1) {
                    cx = next[cx];
                    if (cx == y) {
                        cout << sx << '\n';
                        next[x] = y;
                        break;
                    } else {
                        sx += cx;
                    }
                }
                if (next[cy] != -1) {
                    cy = next[cy];
                    if (cy == x) {
                        cout << sy << '\n';
                        next[y] = x;
                        break;
                    } else {
                        sy += cy;
                    }
                }
            }
        }
    }
}
