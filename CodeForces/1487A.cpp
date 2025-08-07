#include <bits/stdc++.h>
using namespace std;
int t, n, a, minum, minn;
void solve() {
    int n, a, minum = 0, minn = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a == minn) minum++;
        if(i == 1 || a < minn) {
            minn = a;
            minum = 1;
        }
    }
    cout << n - minum << '\n';
}
int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
