#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, t;
    string s = "";
    cin >> n >> m >> k;
    for (int i = 1; i <= 4 * k; i++) cin >> t;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) { // so, no0
            if ((m - i) % 2 == 0) s += 'D';
            else s += 'U';
        }
        if (i != m) s += 'L';
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) {
            if (i % 2 == 0) s += 'D';
            else s += 'U';
        }
        if (i != m) s += 'R';
    }
    cout << s.size() << '\n' << s;
    return 0;
}
