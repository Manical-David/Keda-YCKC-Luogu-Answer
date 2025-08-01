#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 1e5 + 100;
long long a[N], sum[N];
signed main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    long long n, x;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cin >> x;
    int ans = x / sum[n];
    x = x - ans * sum[n];
    for(int i = 1; i <= n; i++) {
        if(sum[i] >= x) {
            cout << i + ans * n;
            return 0;
        }
    }
    return 0;
}