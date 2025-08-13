#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }
    for (int k = 1; k <= n; ++k) {
        int t_max = n / k;
        int l = 0, r = t_max;
        int t = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0) {
                t = mid;
                l = mid + 1;
            } else {
                int pos = mid * k;
                if (pos > n) {
                    r = mid - 1;
                    continue;
                }
                int prev_pos = (mid - 1) * k;
                long long stg = sum[pos] - sum[prev_pos];
                if (stg > s) {
                    t = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        long long c1 = 0;
        if (t > 0) {
            c1 = sum[t * k] - t * (long long)s;
        }
        long long c2 = 0;
        int tong = n - t * k;
        if (tong > 0) {
            int r_max = min(k - 1, tong);
            if (r_max > 0) {
                int pos = t * k + r_max;
                long long s_t = sum[pos] - sum[t * k];
                if (s_t > s) {
                    c2 = sum[pos] - (t + 1) * (long long)s;
                }
            }
        }
        long long maxx = max({c1, c2, 0LL});
        cout << maxx << '\n';
    }

    return 0;
}
