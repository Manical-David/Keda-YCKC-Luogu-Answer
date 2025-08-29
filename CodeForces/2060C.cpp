#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 5;
int a[N];
void solve() {
    memset(a, 0, sizeof(a));
    int sc = 0, n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < k / 2 + 1; i++) {
        if(i << 1 == k) {
            sc += a[i] >> 1; 
            continue;
        }
        sc += min(a[i], a[k - i]);
    }
    cout << sc << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
策略
A 是先手，所以考虑他随便选了一个，此时看 B，他一定会尽量选可以相加为 k 的，如果没有可以选的就可以选同样对答案没有贡献的。
结果
答案是一组符合条件的数中数量少的那个然后相加。
*/