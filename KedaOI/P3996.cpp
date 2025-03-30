#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	multiset <string> s;
	for (int i = 0; i < n; i++) {
		string name;
		getline(cin, name);
		s.insert(name);
	}
	for (auto it = s.begin(); it != s.end(); it = s.upper_bound(*it)) {
		cout << *it << ' ';
		cout << fixed << setprecision(4) << s.count(*it) / (double)n * 100 << "%\n";
	}
	return 0;
}