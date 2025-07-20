#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
struct node {
    int l, r;
} tr[N];
int n;
int dfs_depth(int root) {
    if (tr[root].l == 0 && tr[root].r == 0) return 1;
    int max_depth = 0;
    if (tr[root].l != 0) {
        max_depth = max(max_depth, dfs_depth(tr[root].l));
    }
    if (tr[root].r != 0) {
        max_depth = max(max_depth, dfs_depth(tr[root].r));
    }
    return max_depth + 1;
}
int bfs_depth(int root) {
    if (tr[root].l == 0 && tr[root].r == 0) return 1;
    queue<pair<int, int>> q;
    q.push(make_pair(root, 1));
    int max_depth = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int ver = t.first, depth = t.second;
        max_depth = max(max_depth, depth);
        if (tr[ver].l != 0) q.push(make_pair(tr[ver].l, depth + 1));
        if (tr[ver].r != 0) q.push(make_pair(tr[ver].r, depth + 1));
    }
    return max_depth;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tr[i].l >> tr[i].r;
    }
    cout << bfs_depth(1) << '\n';
    return 0;
}