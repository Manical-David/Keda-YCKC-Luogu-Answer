#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x;
    cin >> x;
    bool flag = false;
    if(x % 3 == 0) {
        cout << 3 << ' ';
        flag = true;
    }
    if(x % 5 == 0) {
        cout << 5 << ' ';
        flag = true;
    }
    if(x % 7 == 0) {
        cout << 7 << ' ';
        flag = true;
    }    
    if(!flag) cout << 'n';
    return 0;
}