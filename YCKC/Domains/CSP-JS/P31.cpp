#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N];
int n, m;
bool check(int mid) {
	int cnt = 1;
	int now = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > mid) return false;
		now += a[i];
		if(now > mid) {
			cnt++;
			now = a[i];
		}
		else {
			continue;
		}
	}
	return cnt <= m;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 1e9;
	while(r > l) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r << '\n';
	return 0;
}