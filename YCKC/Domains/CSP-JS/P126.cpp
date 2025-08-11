#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[25][25][25];
bool vis[25][25][25];
int mw(int a, int b, int c) {
    if (a <= 0 or b <= 0 or c <= 0)
        return 1;
    if (a > 20 or b > 20 or c > 20)
        return mw(20, 20, 20);
    if (vis[a][b][c])
        return w[a][b][c];
    if (a < b and b < c)
        w[a][b][c] = mw(a, b, c - 1) + mw(a, b - 1, c - 1) - mw(a, b - 1, c);
    else
        w[a][b][c] = mw(a - 1, b, c) + mw(a - 1, b - 1, c) + mw(a - 1, b, c - 1) - mw(a - 1, b - 1, c - 1);
    vis[a][b][c] = true;
    return w[a][b][c];
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c;
    memset(vis, false, sizeof(vis));
    cin >> a >> b >> c;
    while (a != -1 or b != -1 or c != -1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << mw(a, b, c) << '\n';
        cin >> a >> b >> c;
    }
    return 0;
}