#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
int n, a[N], b[N];
long long sum[N], res = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        res += a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(b + 1, b + n + 1, a[i]) - b;
        long long answer = res - sum[pos - 1];
        printf("%lld%c", answer, " \n"[i == n]);
    }
    return 0;
}