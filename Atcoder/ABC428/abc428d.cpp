#include <bits/stdc++.h>
using namespace std;
int dign(long long n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}
long long pow10(int k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= 10;
    }
    return res;
}
long long sf(long long n) {
    if (n < 0) return -1;
    long long x = (long long)sqrtl(n);
    while (x * x > n) x--;
    while ((x + 1) * (x + 1) <= n) x++;
    return x;
}
int solve(int C, long long D) {
    long long c_p1 = C + 1;
    long long c_pd = C + D;
    int mink = dign(c_p1);
    int maxk = dign(c_pd);
    int cnt = 0;
    for (int k = mink; k <= maxk; ++k) {
        long long L_k = pow10(k - 1);
        long long R_k = pow10(k) - 1;
        long long A = max(c_p1, L_k);
        long long B = min(c_pd, R_k);
        if (A > B) continue;
        long long pow_10k = pow10(k);
        long long l = C * pow_10k + A;
        long long h = C * pow_10k + B;
        long long s_max = sf(h);
        if (s_max < 0) continue;
        long long s_min;
        if (l == 0) {
            s_min = 0;
        } else {
            long long prev = l - 1;
            long long sqrt_prev = sf(prev);
            s_min = sqrt_prev + 1;
        }
        if (s_min > s_max) continue;
        cnt += s_max - s_min + 1;
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int C;
        long long D;
        cin >> C >> D;
        cout << solve(C, D) << '\n';
    }
    return 0;
}
