#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a < 60 && b >= 60) cout << 1;
    else if(a >= 60 && b < 60) cout << 1;
    else cout << 0;
    return 0;
}