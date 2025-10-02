#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp;
    for (int x : a) {
        auto it = upper_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << dp.size() << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// Note: 不就是最长上升子序列吗