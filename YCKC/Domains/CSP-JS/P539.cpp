#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 2 != 0) {
            for (int i = 1; i <= 2; i++) {
                for (int i = 2; i <= n - 1; i++) {
                    cout << i << " ";
                }
            }
        }
        else {
            for (int i = 2; i <= n - 1; i++) {
                cout << i << " ";
            }
            for (int i = n - 1; i > 1; i--) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}