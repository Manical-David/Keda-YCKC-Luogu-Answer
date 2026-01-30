#include <bits/stdc++.h>
using namespace std;
struct language {
    bool tak = false;
    bool auk = false;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    string s, t;
    int q;
    cin >> n >> m >> s >> t >> q;
    map <char, language> mp;
    for (char c : s) {
        mp[c].tak = true;
    }
    for (char c : t) {
        mp[c].auk = true;
    }
    while (q--) {
        string word;
        cin >> word;
        bool taka = true, auki = true;
        for (char c : word) {
            if (mp[c].tak == false) {
                taka = false;
            }
            else if (mp[c].auk == false) {
                auki = false;
            }
        }
        if ((taka && auki) || (!taka && !auki)) {
            cout << "Unknown\n";
        }
        else if (taka && !auki) {
            cout << "Takahashi\n";
        }
        else if (!taka && auki) {
            cout << "Aoki\n";
        }
    }
    return 0;
}