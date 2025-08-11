#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());
    int l = 1, r = n;
    long long ans = 0;
    for (int ci : c) {
        if (l >= r) {
            break;
        }
        ans += 1LL * ci * (r - l);
        l++;
        r--;
    }
    cout << ans << '\n';
    return 0;
}