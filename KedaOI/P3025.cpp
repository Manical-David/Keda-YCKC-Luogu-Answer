#include <bits/stdc++.h>
using namespace std;
int count(const array<int, 26>& cd, int k) {
    int cnt = 0;
    for (int count : cd) {
        if (count == k) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> dishes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dishes[i];
    }
    int maxcnt = 0;
    for (int s = 0; s < (1 << n); ++s) {
        array<int, 26> cd = {0};
        int chosed = 0;
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                chosed++;
                if (chosed < k) {
                    continue;
                }
                for (char ccd : dishes[i]) {
                    cd[ccd - 'a']++;
                }
            }
        }
        int anscd = count(cd, k);
        maxcnt = max(maxcnt, anscd);
    }
    cout << maxcnt << endl;
    return 0;
}