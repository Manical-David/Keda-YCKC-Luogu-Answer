#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int t;
    cin >> s >> t;
    for (int i = 0; i < t; ++i) {
        int pos;
        string str;
        cin >> pos >> str;
        s.insert(pos, str);
    }
    cout << s << endl;
    return 0;
}