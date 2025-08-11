#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> s, b;
int a = INT_MAX;
void c(int d, int e1, int e2) {
    if (d == n) {
        if (e1 != 1 || e2 != 0) {
            int f = abs(e1 - e2);
            if (f < a) {
                a = f;
            }
        }
        return;
    }
    c(d + 1, e1, e2);
    c(d + 1, e1 * s[d], e2 + b[d]);
}
int main() {
    cin >> n;
    s.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> b[i];
    }
    c(0, 1, 0);   
    cout << a << endl;
    return 0;
}