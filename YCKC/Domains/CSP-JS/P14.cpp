#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int> (n, 0));
    while (m--) {
        int k, b, c, d;
        cin >> k >> b >> c >> d;
        k -= 1, b -= 1, c -= 1, d -= 1;
        for (int i = k; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                a[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}