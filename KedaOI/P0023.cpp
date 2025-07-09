#include<bits/stdc++.h>
using namespace std;
char a[20] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int b[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int main() {
	int m, sum = 0;
	cin >> m;
	char n[256];
	while(m--) {
		cin >> n;
		int ans = 0;
		for(int i = 0; i < 17; i++) {
			ans = ans + (n[i] - '0') * b[i];
		}
		ans %= 11;
		if(a[ans] == n[17]) {
			cout << "True\n";
		}
        else {
			cout << "False\n";
		}
	}
	return 0;
}
