#include <bits/stdc++.h>
using namespace std;
long long get_min_num(const vector<int>& dd, int len, long long n) {
    string s(len, '0');
    long long res = -1;
    function<void(int, bool)> dfs = [&](int pos, bool lim) {
        if (pos == len) {
            long long val = stoll(s);
            if (val >= n && (res == -1 || val < res)) res = val;
            return;
        }
        for (int d : dd) {
            if (pos == 0 && d == 0) continue; // 0s
            if (lim && d < (n / (long long)pow(10, len - pos - 1)) % 10) continue;
            s[pos] = d + '0';
            dfs(pos + 1, lim && (d == (n / (long long)pow(10, len - pos - 1)) % 10));
        }
    };
    dfs(0, true);
    return res;
}
long long solve(long long n, int k) {
    string sn = to_string(n);
    int len = sn.size();
    if (k == 10) return n;
    if (k == 1) {
        long long ans = stoll(string(len, sn[0]));
        if (ans < n) {
            if (sn[0] == '9') {
                ans = stoll(string(len + 1, '1'));
            } else {
                ans = stoll(string(len, sn[0] + 1));
            }
        }
        return ans;
    }
    long long res = -1;
    vector<int> dd;
    for (int msk = 1; msk < (1 << 10); ++msk) {
        if (__builtin_popcount(msk) > k) continue; // msk 二进制 1 cnt
        dd.clear();
        for (int d = 0; d < 10; ++d) {
            if (msk & (1 << d)) dd.push_back(d);
        }
        string s = sn;
        bool ok = true, changed = false;
        for (int i = 0; i < len; ++i) {
            bool found = false;
            for (int d : dd) {
                if (d < s[i] - '0') continue;
                if (d == s[i] - '0') {
                    found = true;
                    break;
                } else {
                    s[i] = d + '0';
                    for (int j = i + 1; j < len; ++j) s[j] = *min_element(dd.begin(), dd.end()) + '0';
                    found = true;
                    changed = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
            if (changed) break;
        }
        if (ok) {
            long long val = stoll(s);
            set<int> used;
            for (char c : s) used.insert(c - '0');
            if ((int)used.size() <= k && val >= n) {
                if (res == -1 || val < res) res = val;
            }
        }
        //更长一位
        if (res == -1) {
            // 构造最小可达数
            if (dd[0] == 0 && dd.size() > 1) {
                long long val = dd[1];
                for (int i = 1; i <= len; ++i) val = val * 10 + dd[0];
                if (val >= n && (res == -1 || val < res)) res = val;
            } else {
                long long val = dd[0];
                for (int i = 1; i <= len; ++i) val = val * 10 + dd[0];
                if (val >= n && (res == -1 || val < res)) res = val;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        int k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}