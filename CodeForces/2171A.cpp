#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int cnt = 0;
        for (int k = 0; k * 4 <= n; ++k) {
            int rem = n - 4 * k;
            if (rem % 2 == 0) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
