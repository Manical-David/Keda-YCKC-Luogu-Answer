#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if(b % a == 0) cout << a + b;
    else cout << b - a;
    return 0;
}