#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    if(n < 1200) cout << "ABC\n";
    else if(n >= 1200 && n < 1500) cout << "ARC\n";
    else if(n >= 1500) cout << "AGC\n";
    return 0;
}