#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <string> mp(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> mp[i];
        }
        for(int i = n; i >= 1; i--) {
            for(int j = 0; j < mp[i].size(); j++) {
                if(mp[i][j] == '#') cout << j + 1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}