#include <bits/stdc++.h>
using namespace std;
long long int n[100005];
int main() {
	long long int n1, x, eat = 0; //n1 = 3, x = 3
	cin >> n1 >> x;
	for (int i = 1; i <= n1; i++) {
		cin >> n[i];
	}
	for (int i = 2; i <= n1; i++) {
		if (n[i] + n[i - 1] > x) {
			eat += n[i] + n[i - 1] - x;
			n[i] -= n[i] + n[i - 1] - x;
		}
	}
	cout << eat;
	return 0;
}