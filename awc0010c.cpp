#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> id(n);
    int reg_c = 0;
    id[0] = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i-1]) > k) {
            reg_c++;
        }
        id[i] = reg_c;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (id[l] == id[r]) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}