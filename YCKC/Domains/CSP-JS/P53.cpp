#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans = 0;
map <int, int> v;
int dfs(int x) {
    if(x < 2) return 0;
    if(v[x]) {
        return v[x];
    }
    else {
        if(x % 2) return v[x] += x + dfs(x / 2) + dfs(x / 2 + 1);
        else {
            return v[x] += x + 2 * dfs(x / 2);
        }
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x;
    cin >> x;
    cout << dfs(x);
    return 0;
}