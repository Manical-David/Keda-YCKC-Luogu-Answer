#include <bits/stdc++.h>
using namespace std;
constexpr int N = 17;
int a[N], u[N], v[N];
int n, m, k;
int res;
void dfs(int x) {
    if(x == m + 1) {
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            if(i == k) continue;
            if(a[i] > a[k]) ans += 1;
        }
        res = min(res, ans);
        return ;
    }
    a[u[x]] += 3;
    dfs(x + 1);
    a[u[x]] -= 3; // 回溯
    a[v[x]] += 3;
    dfs(x + 1);
    a[v[x]] -= 3;
    a[u[x]]++;
    a[v[x]]++;
    dfs(x + 1);
    a[u[x]]--;
    a[v[x]]--;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    res = n + 1;
    dfs(1);
    cout << res << '\n';
    return 0;
}