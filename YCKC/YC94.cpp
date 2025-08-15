#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    int minn = n;
    if (n >= a1) {
        minn = min(minn, n - b1);
    }
    if (n >= a2) {
        minn = min(minn, n - b2);
    }
    if (n >= a3) {
        minn = min(minn, n - b3);
    }
    cout << minn << '\n';
    return 0;
}
