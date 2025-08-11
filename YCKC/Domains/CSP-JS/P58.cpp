#include <bits/stdc++.h>
using namespace std;
bool check(const char* str, const char* p) {
    int i = 0, j = 0;
    while (str[i] != '\0' && p[j] != '\0') {
        if (str[i] == p[j]) {
            j++;
        }
        i++;
    }
    return p[j] == '\0';
}

int main() {
    char str[1009];
    while (cin >> (str + 1)) {
        bool found = false;
        if (check(str + 1, "lhtxdy") || check(str + 1, "lytxdy") || check(str + 1, "llwtxdy")) {
            cout << "escape to home" << endl;
        } else {
            cout << "die on earth" << endl;
        }
    }
    return 0;
}