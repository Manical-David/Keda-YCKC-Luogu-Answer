#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    if (i == n)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}