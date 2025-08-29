#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m, k;
    cin >> m >> n >> k;
    queue <int> b, w;
    for(int i = 1; i <= m; i++) {
        b.push(i);
    }
    for(int i = 1; i <= n; i++) {
        w.push(i);
    }
    while(k--) {
        int t = b.front();
        cout << b.front() << ' ';
        b.pop();
        b.push(t);
        t = w.front();
        cout << w.front() << '\n';
        w.pop();
        w.push(t);
    }
    return 0;
}
