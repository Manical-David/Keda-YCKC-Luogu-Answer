#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin >> a;
    int days = 0;
    while (a > 1) {
        a = floor(a / 2);
        days++;
    }
    cout << days + 1 << endl;
    return 0;
}