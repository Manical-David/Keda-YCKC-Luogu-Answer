#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, a[N], limit;
int main() {
    scanf("%d %d", &n, &limit);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        int sum = (l == r) ? a[l] : a[l] + a[r];
        if (sum > limit) {
            // 说明当前同学体重太重啦
            // 只能自己做一个船了
            r -= 1;
            ans += 1;
        } else {
            // 说明当前同学体重不重
            // 可以和轻的同学一起做一个船
            l += 1;
            r -= 1;
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}