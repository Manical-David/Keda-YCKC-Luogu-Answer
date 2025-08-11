#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e4 + 10;
int a[N], c[N];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	int r = 2;
	int maxx = 0;
	for(int i = 1; i <= n; i++) {
		while(a[r] - a[i] <= k && r <= n) {
			r++;
		}
		c[r] = max(r - i, c[r]);
		maxx = max(maxx, c[i]);
		ans = max(ans, r - i + maxx);
	}
	cout << ans << '\n';
	return 0;
}