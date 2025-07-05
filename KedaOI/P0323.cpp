#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int> g[N];
stack<int> path;
int dg[N];
int n, m;
void dfs(int u) {
    while (!g[u].empty()) {
        int v = g[u].back();
        g[u].pop_back();
        for (auto it = g[v].begin(); it != g[v].end(); ++it) {
            if (*it == u) {
                g[v].erase(it);
                break;
            }
        }
        dfs(v);
    }
    path.push(u);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (dg[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    dfs(start);
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    return 0;
}