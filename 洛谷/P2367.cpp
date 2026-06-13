#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n + 1);
    vector<long long> diff(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
    }
    while (q--) {
        int x, y,z ;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    int minn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + diff[i];
        if (minn > a[i]) {
            minn = a[i];
        }
    }
    cout << minn;
    return 0;
}