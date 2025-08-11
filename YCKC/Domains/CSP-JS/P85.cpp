#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m, k;
    cin >> m >> n >> k;
    queue <int> men, w;
    for(int i = 1; i <= m; i++) {
        men.push(i);
    }
    for(int i = 1; i <= n; i++) {
        w.push(i);
    }
    while(k--) {
        int t = men.front();
        cout << men.front() << ' ';
        men.pop();
        men.push(t);
        t = w.front();
        cout << w.front() << '\n';
        w.pop();
        w.push(t);
    }
    return 0;
}