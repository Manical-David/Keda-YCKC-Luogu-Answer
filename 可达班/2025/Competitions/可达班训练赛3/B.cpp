#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i < n; ++i) { // 预处理前缀和
        pre[i] = pre[i - 1] + (s[i] == 'A' && s[i + 1] == 'C');
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << '\n';
    }
    return 0;
}