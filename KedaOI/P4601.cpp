#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;
struct node {
    int l, r;
} tr[N];

void bfs(int root) {
    /*
        1. 队列，起始元素放入队列
        2. 队列不空
            1. 终止条件
            2. 扩展当前点的邻居节点
    */
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        printf("%d ", t);
        if (tr[t].l != 0) {
            // 说明当前t有左孩子
            q.push(tr[t].l);
        }
        if (tr[t].r != 0) {
            // 说明当前t有右孩子
            q.push(tr[t].r);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tr[i].l, &tr[i].r);
    }

    bfs(1);
    printf("\n");
    return 0;
}