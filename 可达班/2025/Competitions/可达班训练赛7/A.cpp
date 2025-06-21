#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool upp = false, lww = false;
    bool bin[128] = {false};
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') 
            upp = true;
        else if (c >= 'a' && c <= 'z')
            lww = true;
        if (bin[c]) {
            cout << "No" << endl;
            return 0;
        }
        bin[c] = true;
    }
    if (upp && lww) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}
