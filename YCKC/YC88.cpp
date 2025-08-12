#include <bits/stdc++.h>
using namespace std;
string check(int n) {
    if(n % 2 == 0) return "even ";
    else return "odd ";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << check(a) << check(b) << check(a + b) << check(a - b) << check(a * b) << check(a / b);
    return 0;
}