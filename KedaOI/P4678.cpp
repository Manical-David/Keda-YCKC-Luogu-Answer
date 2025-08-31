#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, a[N], sum = 0, dp[N][N];
int dfs(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int ans = -1;
    if (l >= r) {
        ans = a[l];
    } else if (l == r - 1) {
        ans = max(a[l], a[r]);
    } else {
        int p1 = a[l] + min(dfs(l + 2, r), dfs(l + 1, r - 1));
        int p2 = a[r] + min(dfs(l + 1, r - 1), dfs(l, r - 2));
        ans = max(p1, p2);
    }
    dp[l][r] = ans;
    return ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int first = dfs(0, n - 1);
    int second = sum - first;
    if (first >= second) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i] = a[i];
        dp[i][i + 1] = max(a[i], a[i + 1]);
    }
    for (int l = n - 3; l >= 0; l--) {
        for (int r = l + 2; r < n; r++) {
            dp[l][r] = max(a[l] + min(dp[l + 2][r], dp[l + 1][r - 1]),
                           a[r] + min(dp[l + 1][r - 1], dp[l][r - 2]));
        }
    }
    int first = dp[0][n - 1];
    int second = sum - first;
    if (first >= second) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}