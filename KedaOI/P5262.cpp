#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, a[N], f[N], g[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int p1 = 0;
    for(int i = 1; i <= n; i++) {
        p1 += a[i];
    }
    int p2 = 0;
    int sum = 0, maxPresum = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1] + a[i], maxPresum);
        sum += a[i];
        maxPresum - max(maxPresum, sum);
    }
    p2 = f[n];
    sum = 0, maxPresum = 0;
    for(int i = n; i >= 1; i--) {
        g[i] = max(g[i + 1] + a[i], maxPresum);
        sum += a[i];
        maxPresum = max(maxPresum, sum);
    }
    int p3 = INT_MAX;
    for(int i = 1; i <= n; i++) {
        p3 = max(p3, f[i - 1] + g[i]);
    }
    cout << max({p1, p2, p3});
    return 0;
}