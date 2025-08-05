#include <bits/stdc++.h>
using namespace std;
void solve() {
    string a, b;
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << ' ' << b << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}