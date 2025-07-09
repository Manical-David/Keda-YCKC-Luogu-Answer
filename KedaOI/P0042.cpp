#include <bits/stdc++.h>
using namespace std;
const int N = 30010;
int a[N], n, w;
int main() {
    cin >> w >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = n, res = 9;
    while(l <= r) {
        res++;
        if(a[l] + a[r] <= w) l++, r--;
        else r--;
    }
    cout << res - 9 << '\n';
    return 0;
}