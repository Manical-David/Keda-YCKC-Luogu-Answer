#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n, m;
int f(int q) {
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= q) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res != -1 ? res + 1 : -1;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int q;
        scanf("%d", &q);
        printf("%d\n", f(q));
    }
    return 0;
}