#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k, a, b, c;
bool check(long long x) {
    long long cnt = 0;
    for (long long int i = 1; i <= n; i++) {
        int L = 1, R = m, Mid;
        if (c > 0) {
            if (a * i * i + b * i + c * m <= x)
                continue;
            while (L < R) {
                Mid = (L + R) >> 1;
                if (a * i * i + b * i + c * Mid > x)
                    R = Mid;
                else
                    L = Mid + 1;
            }
            cnt += m - R + 1;
        }
        else if (c < 0) {
            if (a * i * i + b * i + c <= x)
                continue;
            while (L < R) {
                Mid = (L + R + 1) >> 1;
                if (a * i * i + b * i + c * Mid > x)
                    L = Mid;
                else
                    R = Mid - 1;
            }
            cnt += L;
        }
        else {
            if (a * i * i + b * i <= x)
                continue;
            cnt += m;
        }
    }
    return cnt < k;
}
int main() {
    scanf("%d%d%lld%lld%lld%lld", &n, &m, &k, &a, &b, &c);
    long long l = -1e18, r = 1e18, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld", r);
    return 0;
}