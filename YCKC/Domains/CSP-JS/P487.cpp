#include <bits/stdc++.h>
#define int long long
using namespace std;
struct f {
	int num;
	bool t;
} a[200100];
bool cmp(f x, f y) {
	if (x.num == y.num) {
		return x.t < y.t;
	}
	return x.num < y.num;
}
signed main() {
	int m, x;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i * 2 - 1].num >> a[i * 2].num;
		a[i * 2 - 1].t = 0;
		a[i * 2].t = 1;
	}
	sort(a + 1, a + m * 2 + 1, cmp);
	int st = a[1].num;
	int cs = 1;
	int tot = 0;
	for (int i = 2; i <= m * 2; i++) {
		if (a[i].t == 0) {
			cs++;
		}
		else {
			cs--;
		}
		if (cs == 0) {
			tot += a[i].num - st + 1;
			st = a[i + 1].num;
		}
	}
	cout << tot << '\n';
	return 0;
}
