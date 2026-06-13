#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    double h, r;
    cin >> h >> r;
    double s = r * r * 3.14, v = s * h;
    cout << ceil(20000 / v);
    return 0; 
}