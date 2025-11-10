#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
map<int, int> mp;
int dfs(int u) {
    if (u < 2) return 0;
    if (mp[u]) return mp[u];
    int l = u / 2;
    int r = (u + 1) / 2;
    mp[u] = dfs(l) + dfs(r) + u;
    return mp[u];
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    cout << dfs(n) << '\n';
    return 0;
}
/*
int res = 0, nowVal = 1;
while(ture) {
    if(nowVal * 2 > n) {
        res += 2 * (n - nowVal);
        break;
    }
    nowVal += 2;
    
}
*/