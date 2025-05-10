#include <bits/stdc++.h>
using namespace std;
bool solve(int num, int t) {
    if (t == 0 && num == 0) return true; // handle t=0 and num=0
    while (num > 0) {
        int digit = num % 10;
        if (digit == t) return true;
        num /= 10;
    }
    return false;
}
int main() {
    int m, t;
    cin >> m >> t;
    int num = 0;
    int ans = 0;
    while (num < m) {
        ans++;
        if (!solve(ans, t)) {
            num++;
        }
    }
    cout << ans << endl;
    return 0;
}
