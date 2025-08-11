#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
int n, b;
int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] >= i - 1) {
			b++;
		} else {
			break;
		}
	}
	cout << b;
	return 0;
}