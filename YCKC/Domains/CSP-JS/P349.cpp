#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cout << n + n / 2 << "\n";
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2) {
        if (i + 2 > n) {
            cout << i;
        }
        else {
            cout << i << " ";
        }
    }
    return 0;
}