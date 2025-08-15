#include <bits/stdc++.h>
using namespace std;
int main() {
    int w, n;
    cin >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l <= r) {
        if (a[l] + a[r] <= w) {
            l++;
            r--;
        } else {
            r--;
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}