#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y;
    cin >> x >> y;
    if(x >= -1 && x <= 1 && y >= -1 && y <= 1) cout << "yes";
    else cout << "no";
    return 0;
}