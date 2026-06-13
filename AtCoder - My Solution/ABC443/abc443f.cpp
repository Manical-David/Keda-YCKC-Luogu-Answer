#include <bits/stdc++.h>
using namespace std;
string fnd_nult(int n) {
    if (n == 1) return "1";
    int m = n * 10;
    vector<int> prev(m, -1);
    queue<int> q;
    for (int d = 1; d <= 9; ++d) {
        int mod = d % n;
        int idx = mod * 10 + d;
        if (prev[idx] == -1) {
            prev[idx] = -2;
            q.push(idx);
            if (mod == 0) return string(1, '0' + d);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int cur_mod = cur / 10;
        int ls = cur % 10;
        for (int d = ls; d <= 9; ++d) {
            int n_mod = (cur_mod * 10 + d) % n;
            int nidx = n_mod * 10 + d;
            if (prev[nidx] == -1) {
                prev[nidx] = cur;
                if (n_mod == 0) {
                    string s;
                    int idx = nidx;
                    while (true) {
                        s.push_back('0' + (idx % 10));
                        if (prev[idx] == -2) break;
                        idx = prev[idx];
                    }
                    reverse(s.begin(), s.end());
                    return s;
                }
                q.push(nidx);
            }
        }
    }
    return "-1";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    cout << fnd_nult(n) << '\n';
    return 0;
}
// Today is for BFS and DFS!