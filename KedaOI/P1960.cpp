#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, a[N];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    int l = 0, r = n - 1;
    while(l < r) {
        res = max(res, min(a[l], a[r]) * (r - l));
        if(a[l] < a[r]) {
            l++;
        } else {
            r--;
        }
    }
    cout << res << endl;
    return 0;
}