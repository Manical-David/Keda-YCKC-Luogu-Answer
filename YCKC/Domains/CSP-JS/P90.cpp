#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int m, n, x, vis[N];
queue<int> q;
int main() {
	cin >> m >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (vis[x]) continue;
		if (q.size() >= m) {
			vis[q.front()] = 0;
			q.pop();
		}
		vis[x] = 1;
		q.push(x);
		cnt++;
	}
	cout << cnt;
	return 0;
}