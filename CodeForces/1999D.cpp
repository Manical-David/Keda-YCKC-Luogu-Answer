#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s, t;
    cin >> s >> t;
    int p = 0; // ->->||
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[p] || s[i] == '?') {
            s[i] = t[p];
            p++;
        }
        if (t.size() == p) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "YES\n";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') cout << 'a';
            else cout << s[i];
        }
        cout << "\n";
    }
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}