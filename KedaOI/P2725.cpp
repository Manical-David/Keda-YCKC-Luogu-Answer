#include <bits/stdc++.h>
using namespace std;
void solve() {
    string str;
    cin >> str;
    int n = stoi(str);
    int sum = 0;
    int length = str.size();
    for(char c : str) {
        sum += pow(c - '0', length);
    }
    if(sum == n) cout << "T\n";
    else cout << "F\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}