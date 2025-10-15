#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int l, r;
    cin >> l >> r;
    cout << l;
    for(int i = l + 1; i <= r; i++) {
        cout << ",\n" << i;
    }
    return 0;
}