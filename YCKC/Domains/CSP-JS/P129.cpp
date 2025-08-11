#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, r, a[N], vis[N];
void dfs(int x) {
    if (x == r + 1) {
        for (int i = 1; i <= r; ++i)
            cout << a[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = a[x - 1] + 1; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}