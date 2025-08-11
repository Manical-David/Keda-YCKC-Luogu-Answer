#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
void solve() {
	stack <unsigned long long> st;
	int n;
	cin >> n;
	while(n--) {
		string str;
		cin >> str;
		if(str == "push") {
			int n;
			cin >> n;
			st.push(n);
		} 
		if(str == "pop") {
			if(!st.empty()) {
				st.pop();
			}
			else cout << "Empty\n";
		}
		if(str == "size") {
			cout << st.size() << '\n';
		}
		if(str == "query") {
			if(!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << "Anguei!\n";
			}
		}
	} 
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		solve();	
	}
	return 0;
}