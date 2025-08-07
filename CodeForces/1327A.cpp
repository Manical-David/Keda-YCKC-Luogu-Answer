#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	if ((n & 1) == (k & 1) && 1ll * k * k <= n) cout << "YES\n";
	else cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}