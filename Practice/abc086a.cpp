#include <bits/stdc++.h>
using namespace std;
bool checkodd(int x) {
    return (x % 2 == 1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y;
    cin >> x >> y;
    cout << (checkodd(x * y) ? "Odd\n" : "Even\n");
    return 0;
}