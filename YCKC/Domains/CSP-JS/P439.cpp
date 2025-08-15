#include <bits/stdc++.h>
using namespace std;
struct cow {
    int eat;
    int time;
} a[100100];
int cmp(cow a, cow b) {
    return a.time * b.eat < a.eat * b.time;
}
int sum[100100];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].eat >> a[i].time;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].eat;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 2 * a[i].time * (sum[n] - sum[i]);
    }
    cout << ans;
    return 0;
}
