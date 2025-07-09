#include <bits/stdc++.h>
using namespace std;
int n, a[100], vis[100];
void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;
        a[x] = i;
        vis[i] = 1;
        dfs(x + 1);
        vis[i] = 0;
    }
}
int main() {
    cin >> n;
    dfs(1);
    return 0;
}