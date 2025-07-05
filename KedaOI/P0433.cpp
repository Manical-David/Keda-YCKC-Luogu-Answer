#include <bits/stdc++.h>
using namespace std;
int encode(const vector<vector<int>>& mat) {
    int res = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (mat[i][j]) res |= (1 << (i * 4 + j));
    return res;
}
vector<vector<int>> decode(int st) {
    vector<vector<int>> mat(4, vector<int>(4, 0));
    for (int i = 0; i < 16; ++i)
        if (st & (1 << i))
            mat[i / 4][i % 4] = 1;
    return mat;
}
int main() {
    vector<vector<int>> strt(4, vector<int>(4)), num(4, vector<int>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            char ch;
            cin >> ch;
            strt[i][j] = ch - '0';
        }
    string du;
    getline(cin, du);
    getline(cin, du);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            char ch;
            cin >> ch;
            num[i][j] = ch - '0';
        }

    int st = encode(strt), ed = encode(num);
    if (st == ed) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    unordered_map<int, int> vis;
    q.push({st, 0});
    vis[st] = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [state, step] = q.front(); q.pop();
        vector<vector<int>> mat = decode(state);
        // 找所有玩具的位置
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (mat[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && mat[ni][nj] == 0) {
                            swap(mat[i][j], mat[ni][nj]);
                            int nstate = encode(mat);
                            if (!vis.count(nstate)) {
                                if (nstate == ed) {
                                    cout << step + 1 << endl;
                                    return 0;
                                }
                                vis[nstate] = step + 1;
                                q.push({nstate, step + 1});
                            }
                            swap(mat[i][j], mat[ni][nj]); // 还原
                        }
                    }
                }
            }
        }
    }
    // 理论上保证有解
    return 0;
}