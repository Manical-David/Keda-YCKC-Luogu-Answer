#include <iostream>
using namespace std;
int main() {
    unsigned long long x, n;
    cin >> x >> n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    unsigned long long res = 1;
    unsigned long long base = x + 1;
    for (int i = 0; i < n; ++i) {
        res *= base;
    }
    
    cout << res << endl;
    return 0;
}