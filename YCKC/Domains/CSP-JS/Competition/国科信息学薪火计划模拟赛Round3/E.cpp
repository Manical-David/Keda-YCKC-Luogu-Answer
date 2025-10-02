#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("joker.in", "r", stdin);
    freopen("joker.out", "w", stdout);
    int n;
    string cds;
    cin >> n >> cds;
    deque<char> pl[11];
    for (int i = 0; i < 53; ++i) {
        int id = i % n;
        pl[id].push_back(cds[i]);
    }
    for (int p = 0; p < n; ++p) {
        bool flag;
        do {
            flag = false;
            for (int i = 0; i < (int)pl[p].size(); ++i) {
                for (int j = i + 1; j < (int)pl[p].size(); ++j) {
                    if (pl[p][i] == pl[p][j]) {
                        pl[p].erase(pl[p].begin() + j);
                        pl[p].erase(pl[p].begin() + i);
                        flag = true;
                        goto recheck;
                    }
                }
            }
            recheck:;
        } while (flag);
    }
    int cur = 0;
    while (true) {
        int nxtp = (cur + 1) % n;
        char cad = pl[nxtp].front();
        pl[nxtp].pop_front();
        bool fnd = false;
        for (int i = 0; i < (int)pl[cur].size(); ++i) {
            if (pl[cur][i] == cad) {
                pl[cur].erase(pl[cur].begin() + i);
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            pl[cur].push_back(cad);
        }
        if (pl[nxtp].empty()) {
            cout << nxtp + 1 << '\n';
            return 0;
        }
        if (pl[cur].empty()) {
            cout << cur + 1 << '\n';
            return 0;
        }
        cur = nxtp;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}