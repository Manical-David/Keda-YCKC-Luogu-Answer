#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
unordered_map<int, int> prims;
void strola(int x) {
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            prims[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        prims[x]++;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        strola(a);
    }
    long long ans = 1;
    for (auto &[p, e] : prims) {
        ans = (ans * (e + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}