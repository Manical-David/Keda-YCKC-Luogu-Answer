#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    if(n % 96 == 0) cout << "Yes\n";
    else {
        string str = to_string(n);
        if(str.find("96") != string::npos) {
            cout << "Yes";
        }
        else cout << "No\n";
    }
    return 0;
}