#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    string l = s.substr(0, n), r = s.substr(n, n);
    unordered_map<string, int> mp;
    for (int mask = 0; mask < (1 << n); ++mask) {
        string black, white;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) black += l[i];
            else white += l[i];
        }
        mp[black + "|" + white]++;
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        string black, white;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) black += r[i];
            else white += r[i];
        }
        reverse(white.begin(), white.end());
        string key = white + "|" + black;
        if (mp.count(key)) ans += mp[key];
    }
    cout << ans << endl;
    return 0;
}