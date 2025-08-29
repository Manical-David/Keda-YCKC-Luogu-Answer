#include <bits/stdc++.h>
using namespace std;
int t;
long long n, m;
bool check(long long x) {
    long long sum = 0;
    for (long long int i = 1; i <= n; i++) {
        long long a = i * i + 100000 * i + n * n - 100000 * n + i * n;
        if (a >= x)
            continue;
        long long L = 1, R = n, j;
        while (L < R) {
            j = (L + R) >> 1;
            long long a = i * i + 100000 * i + j * j - 100000 * j + i * j;
            if (a < x)
                R = j;
            else
                L = j + 1;
        }
        sum += n - R + 1;
    }
    return sum < m;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        long long l = -1e18, r = 1e18, mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}