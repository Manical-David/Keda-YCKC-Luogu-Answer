#include <bits/stdc++.h>
using namespace std;
int main() {
	int a1, a2, t = 0;
	cin >> a1 >> a2;
	while (a1 > 0 && a2 > 0) {
		if (a1 > a2) {
			a2 += 1;
			a1 -= 2;
			t++;
		} else if (a2 > a2) {
			a1 += 1;
			a2 -= 2;
			t++;
		} else {
			a1 += 1;
			a2 -= 2;
			t++;
		}
	}
	cout << t;
	return 0;
}