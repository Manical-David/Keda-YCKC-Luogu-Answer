#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    cin >> str;
    int ans = 0;
    for (char it : str) {
        if (it == '1') ans += 1;
    }
    cout << ans << '\n';
    return 0;
}