#include <bits/stdc++.h>
using namespace std;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int p, q;
bool flag;
bool tong[30][30];
vector<string> a;
bool check(int x, int y) {
    return x >= 0 && x < p && y >= 0 && y < q && !tong[x][y];
}
void dfs(int x, int y, int count) {
    if (flag) return;
    tong[x][y] = true;
    a.push_back(string(1, 'A' + y) + to_string(x + 1));
    
    if (count == p * q) {
        flag = true;
        return;
    }
    vector<pair<int, int>> moves;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny))
            moves.emplace_back(ny, nx);
    }
    sort(moves.begin(), moves.end());
    for (auto [ny, nx] : moves)
        dfs(nx, ny, count + 1);
    if (!flag) {
        tong[x][y] = false;
        a.pop_back();
    }
}
void solve(int i) {
    flag = false;
    a.clear();
    for (int i = 0; i < 30; ++i)
        fill(tong[i], tong[i] + 30, false);
    for (int i = 0; i < p && !flag; ++i)
        for (int j = 0; j < q && !flag; ++j)
            dfs(i, j, 1);
    cout << "Scenario #" << i << ":\n";
    if (flag)
        for (auto &s : a) cout << s;
    else
        cout << "impossible";
    cout << "\n\n";
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> q;
        solve(i);
    }
    return 0;
}