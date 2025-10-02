#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    cout << ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0 ? 'Y' : 'N');
    return 0;
}