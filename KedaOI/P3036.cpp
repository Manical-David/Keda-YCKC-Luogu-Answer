#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3 + 7;
struct node {
    int l, r;
} tr[N];
int n, a[N], b[N];
int dfs(int preL, int preR, int inL, int inR) {
    if (preL > preR || inL > inR) return 0;
    int root = a[preL];
    int rootIndex = -1;
    for (int i = inL; i <= inR; i++) {
        if (b[i] == root) {
            rootIndex = i;
            break;
        }
    }
    int leftSize = rootIndex - inL;
    int left = dfs(preL + 1, preL + leftSize, inL, rootIndex - 1);
    int right = dfs(preL + leftSize + 1, preR, rootIndex + 1, inR);
    tr[root].l = left, tr[root].r = right;
    return root;
}
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        printf("%d ", t);
        if (tr[t].l != 0) {
            q.push(tr[t].l);
        }
        if (tr[t].r != 0) {
            q.push(tr[t].r);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    dfs(1, n, 1, n);
    bfs(a[1]);
    printf("\n");
    return 0;
}