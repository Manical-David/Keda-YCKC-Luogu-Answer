#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;

int n, m, a[N], cuts[N], dp[107][107];

// 把木棍按照cuts[1, m]切除的最小代价
int dfs(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int res = INT_MAX;
    // 递归的终止条件
    if (l > r) {
        res = 0;
    } else if (l == r) {
        // 切一刀的长度
        res = a[r + 1] - a[l - 1];
    } else {  // 枚举切割点
        int tmp = INT_MAX;
        for (int k = l; k <= r; k++) {
            // 切掉了k[l, k - 1], [k], [k + 1, r]
            tmp = min(tmp, dfs(l, k - 1) + dfs(k + 1, r));
        }
        // 切掉k的花费[l, r]的区间长度
        tmp += a[r + 1] - a[l - 1];
        res = tmp;
    }
    dp[l][r] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &cuts[i]);
    }
    sort(cuts, cuts + m);
    a[0] = 0;
    for (int i = 1; i <= m; i++) {
        a[i] = cuts[i - 1];
    }
    a[m + 1] = n;

    printf("%d\n", dfs(1, m));
    return 0;
}