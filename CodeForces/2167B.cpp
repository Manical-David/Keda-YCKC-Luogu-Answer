#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    cout << (str1 == str2 ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}