#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5;
int n, m, l;
long long s, t;
char ok[N + 1];
vector<vector<pair<int,int> > > g(N + 1);
void dfs(int u, int d, long long sum) {
    if (sum > t) return;
    if (d == l) {
        if (sum >= s && sum <= t) ok[u] = 1;
        return;
    }
    for (auto e : g[u]) {
        int v = e.first;
        int c = e.second;
        dfs(v, d + 1, sum + c);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> l >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v;
        int c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    dfs(1, 0, 0);
    bool first = true;
    for (int v = 1; v <= N; ++v) {
        if (ok[v]) {
            if (!first) cout << ' ';
            cout << v;
            first = false;
        }
    }
    cout << '\n';
    return 0;
}