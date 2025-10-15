#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cin.ignore();
    string str;
    getline(cin, str);
    cout << a + b + c << ' ' << str;
    return 0;
}