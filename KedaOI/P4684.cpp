#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &m, &n);

    // 输出我们的编号和我们中位数的个数
    printf("%d %d\n", m, (n + 1) / 2);

    // 建立我们的大小根堆
    priority_queue<int> Big;
    priority_queue<int, vector<int>, greater<int>> Small;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);

        // 1. 如果小根堆是空的或者x >= 小根堆堆顶的
        // 2. 这里也可以写称为如果大根堆是空的，或者x <= 大根堆堆顶
        if (Small.empty() || x >= Small.top()) {
            Small.push(x);
        } else {
            Big.push(x);
        }

        // 因为我们这里是按照小根堆来的，要求小根堆要么元素个数和大根堆一样，要么可以多一个
        // 反过来想，大根堆元素最多只可以和小根堆一样

        // 如果大根堆元素个数比小根堆多了以上，那么把大根堆元素给小根堆一点
        if (Big.size() > Small.size()) {
            Small.push(Big.top());
            Big.pop();
        }
        // 如果小根堆元素个数比大根堆多了一个以上，那么把小根堆元素给大根堆一点
        if (Small.size() > Big.size() + 1) {
            Big.push(Small.top());
            Small.pop();
        }

        if (i & 1) {
            // 输出我们的中位数：在我们这种写法里面，小根堆的堆顶就是我们的中位数
            printf("%d ", Small.top());
            if (++cnt % 10 == 0) printf("\n");
        }
    }
    if (cnt % 10) printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}