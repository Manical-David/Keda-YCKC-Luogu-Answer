#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> a) {
    int n = a.size();
    if (n < 3) return 0;
    int cnt = 0;
    int l = 0;
    int r = 0;
    while (r < n) {
        if (r + 1 < n && a[r + 1] < a[r]) {
            l = r;
            while (r + 1 < n && a[r + 1] <= a[r]) {
                r++;
            }
            if (r < n && a[r] >= a[l]) {
                cnt++;
                l = r;
            } 
            else {
                r = l + 1;
                continue;
            }
        }
        r++;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a) << '\n';
    return 0;
}
