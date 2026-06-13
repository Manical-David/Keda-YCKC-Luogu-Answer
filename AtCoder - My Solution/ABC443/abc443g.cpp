#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 extgcd(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) { x = (a >= 0) ? 1 : -1; y = 0; return llabs(a); }
    int64 x1, y1;
    int64 g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
int64 modinv(int64 a, int64 m) {
    int64 x, y;
    int64 g = extgcd(a, m, x, y);
    if (g != 1) return -1;
    x %= m;
    if (x < 0) x += m;
    return x;
}
long long floor_sum(long long n, long long m, long long a, long long b) {
    if (n <= 0) return 0;
    long long ans = 0;
    while (true) {
        if (a >= m) {
            long long q = a / m;
            __int128 t = (__int128)(n - 1) * n * q / 2;
            ans += (long long)t;
            a %= m;
        }
        if (b >= m) {
            long long q = b / m;
            ans += q * n;
            b %= m;
        }
        __int128 y_max = (__int128)a * n + b; // becaose the testcases was tooooooo big
        if (y_max < m) break;
        n = (long long)(y_max / m);
        b = (long long)(y_max % m);
        swap(a, m);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int64 N, M, A, B;
        cin >> N >> M >> A >> B;
        int64 sum_q = floor_sum(N, M, A, B);
        int64 sum_s;
        if (A == 0) {
            int64 cnt_neg = max<int64>(0, N - (B + 1));
            sum_s = -cnt_neg;
        } else {
            sum_s = floor_sum(N, M, A - 1, B);
        }
        int64 cnt_eq = 0;
        int64 a1 = A - 1;
        int64 D = __gcd(llabs(a1), M);
        if (B % D == 0) {
            int64 Mpp = M / D;
            if (Mpp == 1) {
                cnt_eq = N;
            } else {
                int64 ap = (a1 / D) % Mpp;
                if (ap < 0) ap += Mpp;
                int64 bp = ((- (B / D)) % Mpp + Mpp) % Mpp;
                int64 inv = modinv(ap, Mpp);
                if (inv != -1) {
                    int64 k0 = ( (__int128)inv * bp ) % Mpp;
                    if (k0 < N) cnt_eq = 1 + (N - 1 - k0) / Mpp;
                } else {
                    cnt_eq = 0;
                }
            }
        } else {
            cnt_eq = 0;
        }
        int64 ans = N - (sum_q - sum_s) - cnt_eq;
        cout << ans << '\n';
    }
    return 0;
}