#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        a[x] += c;
    }
    vector<int> pos;
    vector<long long> pre;
    long long sum = 0;
    for (const auto& it : a) {
        pos.push_back(it.first);
        sum += it.second;
        pre.push_back(sum);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto lt = lower_bound(pos.begin(), pos.end(), l);
        int lidx = lt - pos.begin();
        auto rt = upper_bound(pos.begin(), pos.end(), r);
        int ridx = rt - pos.begin();
        long long res = 0;
        if (ridx > 0) {
            res = pre[ridx - 1];
            if (lidx > 0) {
                res -= pre[lidx - 1];
            }
        }
        cout << res << '\n';
    }
    return 0;
}