#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    double a;
    cin >> a;
    if(a < 0) {
        cout << ceil(a);
    }
    else if(a > 0) {
        cout << floor(a);
    }
    else cout << a;
    return 0;
}