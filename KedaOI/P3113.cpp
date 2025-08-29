#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    vector<int> pre(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (s[i - 1] == s[i - 2]) {
            pre[i] += min(val[i - 1], val[i - 2]);
        }
    }
    vector<int> suffix(n + 1, 0);
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1];
        if (s[i] == s[i + 1]) {
            suffix[i] += min(val[i], val[i + 1]);
        }
    }
    long long minn = LLONG_MAX;
    for (int i = 0; i < n - 1; ++i) {
        long long cost = 0;
        if (s[i] == s[i + 1]) {
            cost = pre[i] + suffix[i + 2];
        } else {
            cost = pre[i] + min(val[i], val[i + 1]) + suffix[i + 2];
        }
        if (cost < minn) {
            minn = cost;
        }
    }
    cout << minn << '\n';
    return 0;
}
