#include <bits/stdc++.h>
int n, k, x1, x2, a;
double mx1, mx2, p;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        p = 0.0;
        for (int j = 1; j <= k; j++) {
            scanf("%d", &a);
            p += a;
        }
        p /= k;
        if (mx1 < p) {
            mx2 = mx1, x2 = x1;
            mx1 = p, x1 = i;
        }
        else if (mx2 < p)
            mx2 = p, x2 = i;
    }
    printf("%d\n%d", x1, x2);
    return 0;
}