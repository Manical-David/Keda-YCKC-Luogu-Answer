#include <bits/stdc++.h>

using namespace std;

constexpr int N = 107;

vector<int> g[N];
int n, cnt[N];
bool st[N];

int bfs(int root) {
    int sum = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        int ver = q.front().first, dist = q.front().second;
        q.pop();
        if (st[ver]) continue;
        st[ver] = true;

        sum += cnt[ver] * dist;

        for (const auto &it : g[ver]) {
            if (!st[it]) q.push(make_pair(it, dist + 1));
        }
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int data, l, r;
        scanf("%d %d %d", &data, &l, &r);
        cnt[i] = data;
        if (l != 0) {
            g[i].push_back(l), g[l].push_back(i);
        }
        if (r != 0) {
            g[i].push_back(r), g[r].push_back(i);
        }
    }

    int minn = INT_MAX;
    // 模拟每一个点当作我们的医院
    for (int i = 1; i <= n; i++) {
        memset(st, false, sizeof(st));
        // printf("bfs(%d) = %d\n", i, bfs(i));
        minn = min(minn, bfs(i));
    }
    printf("%d\n", minn);
    return 0;
}