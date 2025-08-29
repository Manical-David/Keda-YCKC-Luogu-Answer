#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    unordered_map<int, unordered_map<int, int>> mp;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int cab, g, im;
            cin >> cab >> g >> im;
            mp[cab][g] = im;
        } else if (op == 2) {
            int cab, g;
            cin >> cab >> g;
            cout << mp[cab][g] << '\n';
        }
    }
    return 0;
}