#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> diff0(n + 2, 0), diff1(n + 2, 0), diff2(n + 2, 0);
    while (m--) {
        int l, r;
        cin >> l >> r;
        int k = l % 3;
        int st = l;
        int t = 0;
        while (st <= r) {
            long long value = 1 + 5 * t;
            int end = st;
            if (k == 1) {
                if (diff1.size() > st) {
                    diff1[st] += value;
                    if (st + 1 <= n + 1) diff1[st + 1] -= value;
                }
            } else if (k == 2) {
                if (diff2.size() > st) {
                    diff2[st] += value;
                    if (st + 1 <= n + 1) diff2[st + 1] -= value;
                }
            } else {
                if (diff0.size() > st) {
                    diff0[st] += value;
                    if (st + 1 <= n + 1) diff0[st + 1] -= value;
                }
            }

            t++;
            st = l + 3 * t;
        }
    }
    vector<long long> res(n + 1, 0);
    long long sum0 = 0, sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 1) {
            sum1 += diff1[i];
            res[i] = sum1;
        } else if (i % 3 == 2) {
            sum2 += diff2[i];
            res[i] = sum2;
        } else {
            sum0 += diff0[i];
            res[i] = sum0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << '\n';
    return 0;
}