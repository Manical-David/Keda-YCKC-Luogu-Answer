#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string str;
    cin >> str;
    if (str[0] == str[str.size() - 1]) {
        cout << "Yes\n";
    }
    else cout << "No\n";
    return 0;
}