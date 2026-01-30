#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int tong = 0;
    while (s.size() < n) {
        s = "o" + s;
    }
    cout << s;
    return 0;
}