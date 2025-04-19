#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int T;
    cin >> s >> T;
    for (int i = 0; i < T; ++i) {
        int pos;
        string str;
        cin >> pos >> str;
        s.insert(pos, str);
    }
    cout << s << endl;
    return 0;
}