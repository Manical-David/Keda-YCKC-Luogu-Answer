/*
    保证任意时刻可以执行的点只有一个

    在拓扑排序中，入度为0点代表可执行点

    要求任意时刻入度为0的点只可以存在一个
*/
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, m, d[N];
vector<int> g[N];

bool topSort() {
    queue<int> q;
    // 把所有入度为0的点放入队列
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }
    // 保证任何时刻只可以存在一个入度为0的点
    if ((int)q.size() > 1) return false;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        // 记录当前执行完t这个事件之后会有多少个事件入度为0（多少个事件变为可执行事件）
        int cnt = 0;
        for (const auto &it : g[t]) {
            d[it] -= 1;
            if (d[it] == 0) {
                cnt += 1;
                q.push(it);
            }
        }
        // 在当前t这个事件完成之后，有不止一个入度为0的点，说明我们有两个及以上的可以执行的事件
        if (cnt > 1) return false;
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        d[v] += 1;
    }

    bool okk = topSort();
    if (okk) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}