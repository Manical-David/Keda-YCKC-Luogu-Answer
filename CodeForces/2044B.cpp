#include <bits/stdc++.h>
using namespace std;
string solve(string str) {
    reverse(str.begin(), str.end());
    for (char &c : str) {
        if (c == 'p') c = 'q';
        else if (c == 'q') c = 'p';
        // 'w' 不变
    }
    return str;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << solve(str) << '\n';
    }
    return 0;
}