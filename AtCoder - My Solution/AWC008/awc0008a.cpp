#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, w, k;
    cin >> n >> w >> k;
    // cout << w / (n - 1) << '\n';
    if (k > (w / (n - 1))) {
        cout << "No";
    }
    else cout << "Yes";
    return 0;
}