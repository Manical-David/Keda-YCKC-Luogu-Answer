#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(abs(a - b) == 1 && ((a >= 1 && b <= 3) || (a >= 4 && b <= 6) || (a >= 6 && b <= 9))) {
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}