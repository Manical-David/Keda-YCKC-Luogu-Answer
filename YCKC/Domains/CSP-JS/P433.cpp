#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(a[i], b[i]);
    }
    cout << ans << endl;
    return 0;
}