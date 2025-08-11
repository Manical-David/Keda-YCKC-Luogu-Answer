#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1010;
int a[N][N], pre[N][N];
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] - pre[x2][y1 - 1] << '\n';
	}
	return (int)0;
} 