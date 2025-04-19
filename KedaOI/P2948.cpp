#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt;
vector<int> v, d;
int ans = 0;
void dfs(int idx, int hp, int picked, int score) {
    if (hp <= 0) return; // 血量归零，直接结束
    if (idx > n) {
        ans = max(ans, score);
    }
    if (picked == cnt) {
        ans = max(ans, score);
        return;
    }
    dfs(idx + 1, hp, picked + 1, score + v[idx]);
    dfs(idx + 1, hp - d[idx], picked, score);
}
signed main() {
    cin >> n >> m >> cnt;
    v.resize(n);
    d.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    dfs(0, m, 0, 0);
    cout << ans << endl;
    return 0;
}