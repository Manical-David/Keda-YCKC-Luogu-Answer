#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], s[200005], s2[200005], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] - a[i - 1];
		s2[i] = s[i] - s[i - 1];
		ans += abs(s2[i]);
	}
	cout << ans;
    return 0;
}