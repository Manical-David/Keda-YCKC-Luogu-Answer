#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, a = 0, b = 0;
    cin >> n;
    vector <unsigned long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            a++;
        }
        else {
            b += 1;
        }
    }
    if (a != 0 && b != 0) {
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    else if (a == 0 || b == 0) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}