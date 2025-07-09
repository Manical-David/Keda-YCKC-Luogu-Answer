#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int n, a[N];
int main() {
    cin >> n;
    a[1] = 1, a[2] = 2;
    for(int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}