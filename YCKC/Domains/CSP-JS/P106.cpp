#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    long long ans = 0;
    int l = 0, r = n - 1;
    int last = 0;
    bool turn = true;
    while (l <= r) {
        int cur;
        if (turn) {
            cur = h[r];
            r--;
        } else {
            cur = h[l];
            l++;
        }
        ans += (cur - last) * (cur - last);
        last = cur;
        turn = !turn;
    }
    cout << ans << endl;
    return 0;
}