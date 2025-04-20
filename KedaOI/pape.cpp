#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 107;
int f[N];
int dfs(int u) {
    if(u == 1) return 1;
    if(u == 2) return 2;
    if(f[u] != 0) return f[u];
    int res = 0;
    res = dfs(u - 1) + dfs(u -2);
    f[u] = res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cout << dfs(100);
    return 0;
}