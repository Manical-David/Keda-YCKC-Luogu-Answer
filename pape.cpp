#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, op;
    cin >> n >> op;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res(n);
    res[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if ((n - 1 - i) % 2 == 1) { 
            res[i] = max(a[i], res[i + 1]);
        } else { 
            res[i] = min(a[i], res[i + 1]);
        }
    }
    int ans = res[0];
    cout << ans << '\n';
    if (op == 1) {
        vector<int> fs;
        for (int i = 1; i < n; ++i) {
            if (res[0] == res[i]) {
                fs.push_back(i + 1);
            }
        }
        sort(fs.begin(), fs.end());
        cout << fs.size() << '\n';
        for (size_t j = 0; j < fs.size(); ++j) {
            if (j > 0) cout << ' ';
            cout << fs[j];
        }
        cout << '\n';
    }

    return 0;
}