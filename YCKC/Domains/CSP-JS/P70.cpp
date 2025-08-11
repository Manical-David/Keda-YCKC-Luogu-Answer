#include <bits/stdc++.h> 
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	queue <int> q;
	int n;
	cin >> n;
	while(n--) {
		int num;
		cin >> num;
		if(num == 1) {
			int x;
			cin >> x;
			q.push(x);
		}
		if(num == 2) {
			if(q.empty()) {
				cout << "ERR_CANNOT_POP\n";
				continue;
			}
			q.pop();
		}
		if(num == 3) {
			if(q.empty()) {
				cout << "ERR_CANNOT_QUERY\n";
				continue;
			}
			cout << q.front() << '\n';
		}
		if(num == 4) {
			cout << q.size() << '\n';
		}
	}
}