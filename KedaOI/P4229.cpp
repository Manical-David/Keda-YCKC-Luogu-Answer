#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, a[N], lmax[N], rmax[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    lmax[1] = a[1];
    for (int i = 2; i <= n; i++) lmax[i] = max(lmax[i - 1], a[i]);
    rmax[n] = a[n];
    for (int i = n - 1; i >= 1; i--) rmax[i] = max(rmax[i + 1], a[i]);
    // 左右两边格子是没有办法存储雨水的
    // 2 ~ n - 1
    long long res = 0;
    for (int i = 2; i <= n - 1; i++) {
        res += max(0, min(lmax[i], rmax[i]) - a[i]);
    }
    printf("%lld\n", res);
    return 0;
}