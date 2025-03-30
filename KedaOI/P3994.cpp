#include <bits/stdc++.h>
using namespace std;
string a[514];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int i = 0;
    string p;
    cin >> p;
    string s;
    unordered_map<string, char> mp;
    while(cin >> s) {
        if(a[p[i]].empty()) {
            if(mp.count(s)) {
                cout << "false";
                return 0;
            }
            a[p[i]] = s;
            mp[s] = p[i];
        }
        else if(a[p[i]] != s) {
            cout << "false";
            return 0;
        }
        i++;
    }
    if(i != p.length()) {
        cout << "false";
        return 0;
    }
    cout << "true";
    return 0;
}