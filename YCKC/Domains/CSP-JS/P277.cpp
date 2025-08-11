#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	stack <int> st;
	for(int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		if(str == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		if(str == "pop") st.pop();
		if(str == "empty") {
			if(st.empty()) cout << "YES\n";
			else cout << "NO\n";
		}
		if(str == "query") cout << st.top() << '\n'; 
	}
}