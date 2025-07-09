#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<int> stock(m);
    for (int i = 0; i < m; ++i) cin >> stock[i];
    int n;
    cin >> n;
    vector<int> need(n);
    for (int i = 0; i < n; ++i) cin >> need[i];
    sort(stock.rbegin(), stock.rend());
    sort(need.rbegin(), need.rend());
    vector<bool> used(n, false);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        vector<bool> vis(n, false);
        function<bool(int, int)> dfs = [&](int remain, int idx) {
            if (remain == 0) return true;
            for (int j = idx; j < n; ++j) {
                if (!used[j] && !vis[j] && need[j] <= remain) {
                    vis[j] = true;
                    used[j] = true;
                    if (dfs(remain - need[j], j + 1)) return true;
                    used[j] = false;
                }
            }
            return false;
        };
        if (dfs(stock[i], 0)) ans++;
    }
    cout << accumulate(used.begin(), used.end(), 0) << endl;
    return 0;
}