#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dep = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (cur > dep) {
            ans += cur - dep;
        }
        dep = cur;
    }
    cout << ans << endl;
    return 0;
}