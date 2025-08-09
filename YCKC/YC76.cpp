#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x;
    cin >> x;
    if(x < 5) cout << "normal\n";
    else if(x >= 5 && x % 2 == 0) cout << "difficult\n";
    else cout << "easy\n";
    return 0;
}