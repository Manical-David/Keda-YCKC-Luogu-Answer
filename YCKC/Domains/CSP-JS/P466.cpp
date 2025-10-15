#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> diff(n + 2, 0);
    while (m--) {
        int l, r;
        cin >> l >> r;
        int cnt = (r - l) / 3 + 1;
        long long a1 = 1;
        long long an = 1 + 5 * (cnt - 1);
        long long sum = cnt * (a1 + an) / 2;
        for (int k = 0; k < cnt; ++k) {
            int pos = l + 3 * k;
            diff[pos] += 1 + 5 * k;
        }
    }
    vector<long long> res(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        res[i] = res[i - 1] + diff[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << '\n';
    return 0;
}
