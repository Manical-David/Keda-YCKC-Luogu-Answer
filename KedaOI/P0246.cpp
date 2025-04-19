#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    cout << str << endl;
    return 0;
}