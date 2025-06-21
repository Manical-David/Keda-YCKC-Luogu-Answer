#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5 * 1e8;
int a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_map<long long, int> cnt;
    cnt[0] = 1;
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        long long key = sum - 1LL * k * i;
        ans += cnt[key];
        cnt[key]++;
    }
    cout << ans << '\n';
    return 0;
}