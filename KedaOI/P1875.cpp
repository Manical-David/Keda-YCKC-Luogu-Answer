#include <bits/stdc++.h>
using namespace std;
constexpr int N = 507;
int n, m, g[N][N];
int dist[N];
bool st[N];
// 求出来从Start到其他所有点的最短距离，如果不存在则是0x3f3f3f3f
void dijkstra(int Start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    // 起点到起点的距离为0
    dist[Start] = 0;
    // 还有n - 1个点未确定
    for (int i = 0; i < n - 1; i++) {
        // t就是不在我们公司的最佳员工
        int t = -1;
        // 遍历所有点找到这个t
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        st[t] = true;
        // 用t更新其他所有点到起点的最短距离
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = min(g[u][v], w);
    }
    dijkstra(1);
    if (dist[n] == 0x3f3f3f3f) dist[n] = -1;
    printf("%d\n", dist[n]);
    return 0;
}