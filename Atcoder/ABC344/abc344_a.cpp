#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    getline(cin, str);
    bool beg = false;
    string ans = "";
    for(char c : str) {
        if(!beg && c == '|') {
            beg = true;
            continue;
        }
        else if(beg && c == '|') {
            beg = false;
            continue;
        }
        if(beg) continue;
        ans.push_back(c);
    }
    cout << ans << '\n';
    return 0;
}