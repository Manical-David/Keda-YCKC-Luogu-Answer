#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false), cin.tie(0);
    string a;
    cin >> a;
    int ans = 0;
    for(char c : a) {
        ans += int(c - '0');
    }
    cout << ans << '\n';
    return 0;
}