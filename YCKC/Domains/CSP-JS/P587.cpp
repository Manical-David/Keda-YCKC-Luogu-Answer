#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> cnts(26, 0);
        for (char c : s) {
            cnts[c - 'a']++;
        }
        int maxx = *max_element(cnts.begin(), cnts.end());
        if (maxx == n) {
            cout << n << '\n';
        } else if (maxx > n - maxx) {
            cout << 2 * maxx - n << '\n';
        } else {
            cout << n % 2 << '\n';
        }
    }
    return 0;
}