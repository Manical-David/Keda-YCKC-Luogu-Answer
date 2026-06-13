#include <bits/stdc++.h>
using namespace std;
double s, v, m;
int n, a, t, b;
int main() {
    cin >> s >> v;
    n = 8 * 60 + 24 * 60;
    t = ceil(s / v) + 10;
    n -= t;
    if (n >= 24 * 60) n -= 24 * 60;
    b = n % 60;
    a = n / 60;
    printf("%02d:%02d", a, b); // 记住，有可能要加0
    return 0;
}
