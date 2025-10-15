#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int bob = 0, alice = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if((i + 1) % 2 == 0) bob += a[i];
        else alice += a[i];
    }
    // cout << "Alice: " << alice << "\nBob: " << bob << '\n';
    cout << abs(alice - bob);
    return 0;
}