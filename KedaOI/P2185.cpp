#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
vector <int> g[N];
long long n, res[N], sonSum[N];
void dfs(int u, int fa) {
    for(const auto &it : g[u]) {
        if(it == fa) continue;
        dfs(it, u);
        sonSum[u] += sonSum[it];
        res[u] += sonSum[it] + res[it];
    }
}
void getRes(int u, int fa) {
    for(const auto &it : g[u]) {
        if(it == fa) continue;
        res[it] = res[u] - sonSum[it] + (n - sonSum[it]);
        getRes(it, u);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n;
    for(int i = 0; i <= n; i++) {
        sonSum[i] = 1; // Initialize sonSum to 1 for each node
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    getRes(0, -1);
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}