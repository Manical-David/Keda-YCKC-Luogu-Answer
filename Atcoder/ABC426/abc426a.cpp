#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string a, b;
    cin >> a >> b;
    map <string, int> mp;
    mp["Ocelot"] = 3;
    mp["Serval"] = 2;
    mp["Lynx"] = 1;
    cout << (mp[a] <= mp[b] ? "Yes" : "No");
    return 0;
}