#include <bits/stdc++.h>
using namespace std;
int getminn(char c1, char c2) {
    if (c1 == c2) return 0;
    int op1 = (c2 - c1 + 26) % 26;
    int op2 = (c1 - c2 + 26) % 26;
    return min(op1, op2);
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int minn = 0;
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        minn += getminn(s[l], s[r]);
    }
    cout << minn << '\n';
    return 0;
}
