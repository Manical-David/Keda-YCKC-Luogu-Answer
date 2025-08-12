#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    cin >> str;
    int ans = 0;
    for(char c : str) {
        ans += (c - '0');
    }
    cout << bool(ans % 13 == 0);
    return 0;
}