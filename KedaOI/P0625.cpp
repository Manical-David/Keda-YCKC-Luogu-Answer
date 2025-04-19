#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int boys = 0, girls = 0;
    for(int i = 0; i <= s.size(); i++) {
        if(s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y') {
            boys++;
        }
        if(s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l') {
            girls++;
        }
    }
    cout << boys << '\n' << girls << '\n';
    return 0;
}