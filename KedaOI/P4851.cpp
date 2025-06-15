#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 150005;
vector<int> G[MAXN];  // 邻接表
int vis[MAXN], T = 0; // 用时间戳方式标记访问
int N, M, Q;
int bfs(int start, int k) {
    T++;
    queue<pair<int, int>> q;
    q.push({start, 0});
    vis[start] = T;
    int res = start;
    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if (d == k) continue;

        for (int v : G[u]) {
            if (vis[v] != T) {
                vis[v] = T;
                res += v;
                q.push({v, d + 1});
            }
        }
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> Q;
    while (Q--) {
        int x, k;
        cin >> x >> k;
        cout << bfs(x, k) << '\n';
    }
    return 0;
}