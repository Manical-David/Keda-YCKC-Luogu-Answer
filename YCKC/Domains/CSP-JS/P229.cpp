#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long ans = 2;
    for (int i = 1; i < n; ++i) {
        ans = (ans + 1) * 2;
    }
    cout << ans << endl;
    return 0;
}
    