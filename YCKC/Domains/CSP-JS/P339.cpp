#include <bits/stdc++.h>
#define int long long
int mode(int a, int b, int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    scanf("%lld", t);
    while(t--) {
        int n, m, t;
        scanf("%lld%lld%lld", &n, &m, &t);
        printf("%lld^%lld mod %lld=%lld\n", n, m, t, mode(n, m, t));
    }
    return 0;
}