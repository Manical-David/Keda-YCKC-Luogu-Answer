#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, target;
    cin >> n >> target;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 1;
    int len = 1, sum = 0, ans = n + 1;
    while (l <= n && r <= n) {
        sum += a[r];
        while (sum >= target) {
            if (len < ans) {
                ans = len;
            }
            sum -= a[l];
            l++;
            len--;
        }
        len++;
        r++;
    }
    if (ans == n + 1) {
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}