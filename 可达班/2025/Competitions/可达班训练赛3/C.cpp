#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 55;
ll len[N], cnt[N];
ll solve(int n, ll x) {
    if (n == 0) {
        return x >= 1 ? 1 : 0;
    }
    if (x == 0) return 0;
    if (x == 1) return 0;
    if (x <= 1 + len[n - 1]) {
        return solve(n - 1, x - 1);
    }
    if (x == 1 + len[n - 1] + 1) {
        return cnt[n - 1] + 1;
    }
    if (x <= 1 + len[n - 1] + 1 + len[n - 1]) {
        return cnt[n - 1] + 1 + solve(n - 1, x - (1 + len[n - 1] + 1));
    }
    return cnt[n];
}
int main() {
    int n;
    ll x;
    cin >> n >> x;
    len[0] = 1;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        len[i] = len[i - 1] * 2 + 3;
        cnt[i] = cnt[i - 1] * 2 + 1;
    }
    cout << solve(n, x) << '\n';
    return 0;
}
