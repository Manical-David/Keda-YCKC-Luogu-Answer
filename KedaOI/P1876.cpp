#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, m, dist[N];
bool st[N];
struct node {
    int to, val;
};
vector <node> g[N];
void digikstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[start]  = 0;
    priority_queue <pair<int, int> , vector <pair <int, int>>, greater<pair<int, int>>>heap;
    heap.push(make_pair(0, start));
    while(!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        if(st[ver]) continue;
        st[ver] = true;
        for (const auto &it : g[ver]) {
            int to = it.to, val = it.val;
            if (dist[to] > dist[ver] + val) {
                dist[to] = dist[ver] + val;
                heap.push(make_pair(dist[to], to));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    digikstra(1);
    if (dist[n] == 0x3f3f3f3f) dist[n] = -1;
    cout << dist[n];
    return 0;
}