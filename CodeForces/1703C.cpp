#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        while (len--) {
            char c;
            cin >> c;
            if (c == 'D') {
                a[i]++;
                if (a[i] == 10)
                    a[i] = 0;
            }
            else if (c == 'U') {
                a[i]--;
                if (a[i] == -1)
                    a[i] = 9;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
