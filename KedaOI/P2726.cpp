#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <bool> a(n, false);
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        a[num] = true;
    }
    bool flag = false;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == false) {
            cout << i << ' ';
            flag = true;
        }
    }
    if(!flag) cout << n;
    return 0;
}