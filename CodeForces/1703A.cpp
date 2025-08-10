#include <bits/stdc++.h>
using namespace std;
void solve() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    if(str == "YES") cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}