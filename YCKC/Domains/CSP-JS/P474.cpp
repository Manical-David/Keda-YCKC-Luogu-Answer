#include <bits/stdc++.h>
using namespace std;
void dfs(vector<string>& g, int x, int y, int n, int m) {
	g[x][y] = (g[x][y] == 'X') ? '.' : 'X';
	if (x > 0)      g[x-1][y] = (g[x-1][y] == 'X') ? '.' : 'X';
	if (x < n-1)    g[x+1][y] = (g[x+1][y] == 'X') ? '.' : 'X';
	if (y > 0)      g[x][y-1] = (g[x][y-1] == 'X') ? '.' : 'X';
	if (y < m-1)    g[x][y+1] = (g[x][y+1] == 'X') ? '.' : 'X';
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int minn = INT_MAX;
	for (int i = 0; i < (1 << m); ++i) {
		vector<string> g = a;
		int num = 0;
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) {
				dfs(g, 0, j, n, m);
				num++;
			}
		}
		for (int j = 1; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (g[j-1][k] == 'X') {
					dfs(g, j, k, n, m);
					num++;
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < m; ++j) {
			if (g[n-1][j] != '.') {
				flag = false;
				break;
			}
		}
		if (flag) {
			minn = min(minn, num);
		}
	}
	cout << minn << '\n';
	return 0;
}
