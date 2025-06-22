#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> fod(M);
    vector<char> res(M);
    for (int i = 0; i < M; ++i) {
        int C;
        cin >> C;
        fod[i].resize(C);
        for (int j = 0; j < C; ++j) {
            cin >> fod[i][j];
            --fod[i][j]; // 0-based
        }
        cin >> res[i];
    }
    int sum = 0;
    int maxx = 1 << N;
    for (int mask = 0; mask < maxx; ++mask) {
        bool flag = true;
        for (int i = 0; i < M && flag; ++i) {
            int cnts = 0;
            for (int food : fod[i]) {
                if (mask & (1 << food)) ++cnts;
            }
            if (res[i] == 'o') {
                if (cnts < K) flag = false;
            } else {
                if (cnts >= K) flag = false;
            }
        }
        if (flag) ++sum;
    }
    cout << sum << endl;
    return 0;
}