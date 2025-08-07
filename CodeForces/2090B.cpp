#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector <vector <bool> > d(n, vector <bool> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j] == '0') break;
            d[i][j] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(b[j][i] == '0') break;
            d[j][i] = true;
        }
    }
    bool res = true;
    for(int i = 0; res && i < n; i++) {
        for(int j = 0; res && j < m; j++) {
            if(b[i][j] == '1' && !d[i][j]) res = false;
        }
    }
    cout << (res ? "YES\n" : "NO\n");
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long t; cin >> t;
    while(t--){
        solve();
    }
}