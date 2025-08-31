#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    if(n % 100 == 0) cout << 100;
    else cout << 100 - n % 100;
    return 0;
}