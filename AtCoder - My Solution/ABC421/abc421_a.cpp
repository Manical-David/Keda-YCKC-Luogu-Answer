#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    vector <string> a(n + 1);
    for(int i = 1; i <= n; i++) {
        getline(cin, a[i]);
    }
    int x;
    string y;
    cin >> x >> y;
    if(a[x] == y) cout << "Yes";
    else cout << "No";
    return 0;
}