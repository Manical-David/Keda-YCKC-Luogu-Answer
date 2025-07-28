#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

// dist[1]代表第一层所有节点的总和是多少
int a[N], dist[N], n;

void dfs(int root, int depth) {
    if (root > n) return;

    dist[depth] += a[root];
    dfs(root * 2, depth + 1);
    dfs(root * 2 + 1, depth + 1);
}

void bfs(int root) {
    queue<pair<int, int>> q;
    q.push(make_pair(root, 1));
    while (!q.empty()) {
        int ver = q.front().first, depth = q.front().second;
        q.pop();

        dist[depth] += a[ver];
        if (ver * 2 <= n) q.push(make_pair(ver * 2, depth + 1));
        if (ver * 2 + 1 <= n) q.push(make_pair(ver * 2 + 1, depth + 1));
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // dfs(1, 1);
    bfs(1);

    int maxx = INT_MIN, pos = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxx) {
            // 为什么不用>=
            maxx = dist[i];
            pos = i;
        }
    }

    printf("%d\n", pos);
    return 0;
}