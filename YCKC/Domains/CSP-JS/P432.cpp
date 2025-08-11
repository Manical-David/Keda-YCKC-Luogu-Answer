#include <bits/stdc++.h>
using namespace std;
int n[1005];
int main() {
	int n1, d;
	cin >> n1 >> d;
	for (int i = 1; i <= 2 * n1; i++) {
		cin >> n[i];
	}
	sort(n + 1, n + n1 * 2 + 1);
	for (int i = 1; i <= 2 * n1; i += 2) {
		if (abs(n[i] - n[i + 1]) > d) {
			cout << "No";
			return 0; 
		}
	}
	cout << "Yes";
	return 0;
}