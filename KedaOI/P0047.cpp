#include <bits/stdc++.h>
#define int long long
using namespace std;
int fibonacci(int n);
signed main() {
    int N;
    cin >> N;
    int ans = fibonacci(N - 1);
    cout << ans << endl;
    return 0;
}
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}