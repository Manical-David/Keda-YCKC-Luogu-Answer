#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie();
	int n;
	cin >> n;
	vector <int> a(n), sum(n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	} 
	return 0;
}