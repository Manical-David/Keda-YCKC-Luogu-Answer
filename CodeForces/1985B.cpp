#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
	int n;
	cin >> n;
	int maxx = 0, ans = n;
	for(int i = 2; i <= n; i++) {
		int sum = 0;
		for(int j = 1; j * i <= n; j++) sum += j * i;
		if(sum > maxx) {
            ans = i; 
            maxx = sum;
        }
	}
	cout << ans << "\n";
}
signed main() {
    int t;
	cin >> t;
	while(t--) {
        solve();
    }
	return 0;
}