#include <bits/stdc++.h>
using namespace std;
const int NR = 1e5 + 5;
long long n, L;
double l = 0, r = 2e3, s[NR], a[NR];
bool check(double mid) {
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - mid; 
	double minn = 0;
	for (int i = L; i <= n; i++) {
		minn = min(minn, s[i - L]); 
		if(s[i] - minn >= 0)
			return 1; 
	}
	return 0;
}
int main() {
	cin >> n >> L;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (r - l > 1e-5) {
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << int(r * 1000);
	return 0;
}
