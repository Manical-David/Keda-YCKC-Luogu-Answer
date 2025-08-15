#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    map <int, pair <int, int> > mp;
    mp[1] = {1, 1}, mp[2] = {1, 2}, mp[3] = {1, 3}, mp[4] = {2, 1}, mp[5] = {2, 2}, mp[6] = {2, 3}, mp[7] = {3, 1}, mp[8] = {3, 2}, mp[9] = {3, 3};
    int a, b;
    cin >> a >> b;
    if(abs(a - b) == 1 && mp[a].first == mp[b].first && abs(mp[a].second - mp[b].second) == 1) cout << "Yes";
    else cout << "No";
    return 0;
}