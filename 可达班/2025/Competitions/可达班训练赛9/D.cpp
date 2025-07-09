#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(26);
    for (int i = 0; i < 26; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    vector<int> count_s(26, 0);
    for (char c : s) {
        count_s[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (count_s[i] > a[i]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    int m = k - n;
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> rem(26);
    for (int i = 0; i < 26; ++i) {
        rem[i] = a[i] - count_s[i];
    }
    vector<int> dp_prev(m + 1, 0);
    dp_prev[0] = 1;
    for (int i = 0; i < 26; ++i) {
        int max_k = rem[i];
        vector<int> pre_sum(m + 1, 0);
        pre_sum[0] = dp_prev[0];
        for (int j = 1; j <= m; ++j) {
            pre_sum[j] = (pre_sum[j - 1] + dp_prev[j]) % MOD;
        }
        vector<int> dp_curr(m + 1, 0);
        for (int j = 0; j <= m; ++j) {
            int k_max = min(max_k, j);
            int lower = j - k_max;
            if (lower <= 0) {
                dp_curr[j] = pre_sum[j] % MOD;
            } else {
                dp_curr[j] = (pre_sum[j] - pre_sum[lower - 1] + MOD) % MOD;
            }
        }
        dp_prev = dp_curr;
    }
    int ans = dp_prev[m];
    if (ans == 0) {
        cout << "impossible" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
