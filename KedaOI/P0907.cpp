#include  <bits/stdc++.h>
using namespace std;
int solve(vector<int>& b, vector<int>& add, int n, int m) {
    sort(add.begin(), add.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        int pos = b[i];
        auto it = lower_bound(add.begin(), add.end(), pos); // 2分
        int l1 = (it != add.end()) ? abs(*it - pos) : INT_MAX;
        int r1 = (it != add.begin()) ? abs(*(it - 1) - pos) : INT_MAX;
        res = max(res, min(l1, r1));
    }
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n), add(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> add[i];
    cout << solve(b, add, n, m) << endl;
    return 0;
}