#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct node {
	int x, y;
	node(int _x, int _y) : x(_x), y(_y) {}
};
void coutt(vector<vector<node>>& prev, node end) {
	stack<node> path;
	node curr = end;
	while (!(curr.x == 0 && curr.y == 0)) {
		path.push(curr);
		curr = prev[curr.x][curr.y];
	}
	path.push(node(0, 0));
	while (!path.empty()) {
		node p = path.top();
		cout << "(" << p.x << "," << p.y << ")" << endl;
		path.pop();
	}
}
void bfs(int g[N][N]) {
	queue<node> q;
	vector<vector<bool>> vis(N, vector<bool>(N, false));
	vector<vector<node>> prev(N, vector<node>(N, node(-1, -1)));
	q.push(node(0, 0));
	vis[0][0] = true;
	while (!q.empty()) {
		node curr = q.front();
		q.pop();
		if (curr.x == N-1 && curr.y == N-1) {
			coutt(prev, node(N-1, N-1));
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && g[nx][ny] == 0 && !vis[nx][ny]) {
				vis[nx][ny] = true;
				prev[nx][ny] = curr;
				q.push(node(nx, ny));
			}
		}
	}
}
signed main() {
	int g[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> g[i][j];
		}
	}
	bfs(g);
	return 0;
}
