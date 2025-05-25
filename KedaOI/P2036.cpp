#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1 << 24;

int n, m, k;
int g[57], weights[N];
int cnt = 0, ans = 0;

// 暴力枚举前一半的所有可能
void dfs1(int u, int s) {
    if (u == k) {
        // 递归的终止条件：遍历完前n / 2个元素了
        weights[cnt++] = s;
        return;
    }
    // 搜索树的分裂条件：1. 选择当前第u个物品。 2. 不选当前第u个物品
    if ((long long)s + g[u] <= m) dfs1(u + 1, s + g[u]);
    dfs1(u + 1, s);
}

// 遍历后一半的所有可能，然后与前一半结合
void dfs2(int u, int s) {
    if (u == n) {
        // 递归终止条件：遍历完所有的元素了
        // 当前后一半的总体积是s，在前一半中找最后一个<= m - s的元素是什么
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (weights[mid] + (long long)s <= m) {
                // 可以再大点
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (weights[l] + (long long)s <= m) ans = max(ans, weights[l] + s);
        return;
    }
    // 搜索树的分裂条件：1. 选择当前第u个物品。 2. 不选当前第u个物品
    if ((long long)s + g[u] <= m) dfs2(u + 1, s + g[u]);
    dfs2(u + 1, s);
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) scanf("%d", &g[i]);

    sort(g, g + n, greater<int>());
    // 区分前一半和后一半
    k = n / 2;
    dfs1(0, 0);
    // weights数组后续要二分查找：满足单调性
    sort(weights, weights + cnt);
    // set和sort时间都是nlogn，但是实际使用上sort比set快很多
    // weights去重：unquie,手动去重
    int t = 1;
    for (int i = 1; i < cnt; i++) {
        if (weights[i] != weights[i - 1]) {
            // 当前遇到了一个新的元素，之前连续的元素被断开了
            weights[t++] = weights[i];
        }
    }
    cnt = t;
    // 遍历后一半的所有可能的元素，然后去前一半二分查找满足条件的元素
    dfs2(k, 0);
    printf("%d\n", ans);
    return 0;
}