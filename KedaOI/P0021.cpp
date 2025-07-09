#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;
    int maxn = 0, minn = 101;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            maxn = max(maxn, cnt[i]);
            minn = min(minn, cnt[i]);
        }
    }
    int diff = maxn - minn;
    if (is_prime(diff)) {
        cout << "Lucky Word" << endl;
        cout << diff << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}