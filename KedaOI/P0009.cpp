#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    for (int x = 0; x <= 10000; x++) {
        for (int y = 0; y <= 10000; y++) {
            if (a * x + b * y + c == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}