#include <bits/stdc++.h>
using namespace std;
int stanf(const string &s) {
    int open = 0, close = 0, res = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            close++;
        }
        if (close > open) {
            res++;
            close--;
            open++;
        }
    }
    res += (open - close) / 2;
    return res;
}
int main() {
    string s;
    cin >> s;
    cout << stanf(s) << '\n';
    return 0;
}
