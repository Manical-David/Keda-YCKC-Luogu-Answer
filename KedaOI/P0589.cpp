#include <bits/stdc++.h>
using namespace std;
bool check(const string& s1, const string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    string doubleS1 = s1 + s1;
    for (int i = 0; i < len1; ++i) {
        string lsed = doubleS1.substr(i, len1);
        if (lsed.find(s2) != string::npos) {
            return true;
        }
    }
    return false;
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bool res1 = check(s1, s2);
    bool res2 = check(s2, s1);
    if (res1 || res2) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
