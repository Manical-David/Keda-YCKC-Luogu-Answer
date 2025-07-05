#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
stack<int> path;
int din[N], dout[N];
int n, m;
void dfs(int u) {
    while (!g[u].empty()) {
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
    }
    path.push(u);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        dout[u]++;
        din[v]++;
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end(), greater<int>());
    }
    int start = 1, cnt_start = 0, cnt_end = 0;
    bool has_path = true;
    for (int i = 1; i <= n; i++) {
        int diff = dout[i] - din[i];
        if (diff == 1) {
            cnt_start++;
            start = i;
        } else if (diff == -1) {
            cnt_end++;
        } else if (diff != 0) {
            has_path = false;
        }
    }
    if (!has_path || cnt_start > 1 || cnt_end > 1) {
        cout << "No\n";
        return 0;
    }
    if (cnt_start == 0) {
        for (int i = 1; i <= n; i++) {
            if (dout[i] > 0) {
                start = i;
                break;
            }
        }
    }
    dfs(start);
    if (path.size() != m + 1) {
        cout << "No\n";
        return 0;
    }
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    return 0;
}