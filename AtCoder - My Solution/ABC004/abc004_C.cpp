#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	string a = "123456";
	int N;
	cin >> N;
	for (int i = 0; i < N % 30; i++) {
		swap(a[(i % 5)], a[(i % 5) + 1]);
	}
	cout << a << endl;
    return 0;
}
