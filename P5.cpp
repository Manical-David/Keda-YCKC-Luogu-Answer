#include <bits/stdc++.h>
using namespace std;
int a[100100] = {0};
int sum[1000010] = {0};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, w;
    cin >> n >> w;
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[x] += y;
        ma = max(ma, x);
    }
    int ans = 0;
    for(int i = 1; i <= ma; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    if(w >= ma) ans = sum[ma];
    else {
        for(int i = w; i <= ma; i++) {
            ans = max(ans, sum[i] - sum[i - w]);
        }
    }
    cout << ans << '\n';
    return 0;
}