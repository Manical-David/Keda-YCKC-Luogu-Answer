#include <bits/stdc++.h>
using namespace std;
constexpr int N = 20;
int n, m, w[N], sum[N];
int ans = N;
void dfs(int u, int k) {
    if(k == ans) return ;
    if(u == n) {
        ans = min(ans, k);
        return;
    }
    for(int i = 0; i < k; i++) {
        if(sum[i] + w[u] <= m) {
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];
        }
    }
    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
