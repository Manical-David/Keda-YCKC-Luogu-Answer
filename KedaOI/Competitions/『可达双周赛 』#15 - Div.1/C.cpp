#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, ans;
    cin >> s;
    int n = s.size();
    ans = s;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            string t = s;
            reverse(t.begin() + l, t.begin() + r + 1);
            if (t < ans) ans = t;
        }
    }
    cout << ans << endl;
    return 0;
}