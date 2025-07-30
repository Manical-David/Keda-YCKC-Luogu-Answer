#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    set<long long> a;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.insert(x);
    }
    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        if (a.find(x) != a.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}