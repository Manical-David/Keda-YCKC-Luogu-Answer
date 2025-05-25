#include <bits/stdc++.h>

using namespace std;

constexpr int N = 57;

// g[i]代表选择了i个人构成的门派可能的武力值是多少
set<int> g[N];
int n, k, a[N];

void solve() {
    for (int i = 0; i < N; i++) g[i].clear();

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // 暴力求取前一半的所有可能给存储下来
    int t = n >> 1;
    for (int i = 0; i < (1 << t); i++) {
        // cnt代表我们当前i二进制有几个1 ：选择了几个同学
        // res代表我们选择cnt个同学构成的门派的武力值
        int cnt = 0, res = 0;
        for (int j = 0; j < t; j++) {
            if ((i >> j) & 1) {
                // i的二进制下第j位是1，代表选择第j个元素
                res ^= a[j];
                cnt += 1;
            }
        }
        // 用cnt个人组成的门派可能性多了一个res
        g[cnt].insert(res);
    }

    // 暴力求取后一半的所有可能
    int t2 = n - t;
    for (int i = 0; i < (1 << t2); i++) {
        int cnt = 0, res = 0;
        for (int j = 0; j < t2; j++) {
            if ((i >> j) & 1) {
                // 这里是后一半，下标虽然是从0开始的，但是你得手动偏移一下
                res ^= a[j + t];
                cnt += 1;
            }
        }
        // 我们当前后半部分选择了cnt个同学，需要前一半选择k - cnt个同学并且能力值得是res
        // res ^ res = 0
        if (cnt <= k && g[k - cnt].count(res)) {
            printf("yes\n");
            return;
        }
    }
    printf("no\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}