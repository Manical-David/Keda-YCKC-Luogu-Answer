#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    string n;
    cin >> n;
    int num = stoi(n);
    if(num > 0) {
        n = " " + n;
    }
    else if(num < 0) cout << "-";
    reverse(n.begin() + 1, n.end());
    string tong = "";
    for(int i = 1; i < n.size(); i++) {
        tong += n[i];
    }
    num = stoi(tong);
    cout << num;
    return 0;
}