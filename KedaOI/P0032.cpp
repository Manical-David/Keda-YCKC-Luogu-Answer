#include <bits/stdc++.h>
using namespace std;
constexpr int N = 37;
int n, m, a[N];
void dfs(int u, int start) {
    if (u == m + 1) {
        for (int i = 1; i <= m; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++) {
        a[u] = i;
        dfs(u + 1, i + 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    dfs(1, 1);
    return 0;
}