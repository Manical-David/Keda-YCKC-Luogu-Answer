#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool isCube = false;
    for (int x = 1; x * x * x <= n; ++x) {
        if (x * x * x == n) {
            isCube = true;
            break;
        }
    }
    cout << (isCube ? "Yes" : "No") << '\n';
    return 0;
}