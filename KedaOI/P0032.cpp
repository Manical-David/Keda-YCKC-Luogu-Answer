#include <bits/stdc++.h>

using namespace std;

constexpr int N = 37;

// 从n个数里面选择m个数字
int n, m, a[N];

// u是当前选到了第几个元素
// start是本次从哪一个位置开始选择
void dfs(int u, int start) {
    // 搜索树的终止条件 - 选够m个就停止
    if (u == m + 1) {
        // 本次要选择第m + 1个数字
        // 直接输出答案，不选择m + 1直接停止
        for (int i = 1; i <= m; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    // 搜索树的分裂条件 - 从start开始进行选择
    for (int i = start; i <= n; i++) {
        // 假设当前第u个位置选择的数字是i
        a[u] = i;
        // 向下分裂了
        dfs(u + 1, i + 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(1, 1);
    return 0;
}