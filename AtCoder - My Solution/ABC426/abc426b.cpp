#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    cin >> str;
    int cnt1 = 1, cnt2 = 1;
    char c1 = str[0], c2;
    for(char c : str) {
        if(c1 != c) {
            c2 = c;
            cnt2++;
        }
        else if(c1 == c) {
            cnt1++;
        }
    }
    if(cnt2 > cnt1) {
        cout << c1;
    }
    else if(cnt1 > cnt2) {
        cout << c2;
    }
    return 0;
}