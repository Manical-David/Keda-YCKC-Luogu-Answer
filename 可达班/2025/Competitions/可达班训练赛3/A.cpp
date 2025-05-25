#include <bits/stdc++.h>
using namespace std;
void solve(string n) {
    int cnt = 0;
    for(char c : n) {
        if(c == '4' || c == '7') {
            cnt++;
        }
    }
    if(cnt == 4 || cnt == 7) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    string str;
    while(n--) {
        cin >> str;
        solve(str);
    }
    return 0;
}