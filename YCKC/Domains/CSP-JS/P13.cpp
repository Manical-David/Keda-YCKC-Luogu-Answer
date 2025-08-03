#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> d(n + 1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int s, e, h;
        cin >> s >> e >> h;
        d[s - 1] += h;
        if (e < n) {
            d[e] -= h;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            d[i] += d[i - 1];
        }
        a[i] += d[i];
    }
    int minn = INT_MAX;
    for(int i = 0; i < n; i++) {
        minn = min(minn, a[i]);
    }
    cout << minn;
    return 0;
}
