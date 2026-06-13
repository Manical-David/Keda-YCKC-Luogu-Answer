#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << (sum >= m ? "Yes" : "No");
    return 0;
}