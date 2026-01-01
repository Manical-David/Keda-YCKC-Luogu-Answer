#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int it : ans) {
        cout << it + 1 << ' ';
    }
    puts("");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}