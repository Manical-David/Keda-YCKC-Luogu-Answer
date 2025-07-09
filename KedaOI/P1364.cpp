#include <bits/stdc++.h>
using namespace std;
struct state {
    int s, n, m, step;
};
int S, N, M;
bool tar(int s, int n, int m) {
    int half = S / 2;
    return (s == half && (n == half || m == half)) || 
           (n == half && (s == half || m == half)) ||
           (m == half && (s == half || n == half));
}
int bfs() {
    queue<state> q;
    set<tuple<int, int, int>> vis;
    q.push({S, 0, 0, 0});
    vis.insert({S, 0, 0});
    while (!q.empty()) {
        auto [s, n, m, step] = q.front();
        q.pop();
        if (S % 2 == 0 && tar(s, n, m)) {
            return step;
        }
        // 6种倒法
        int ns, nn, nm;
        // S->N
        ns = max(0, s - (N - n));
        nn = min(N, s + n);
        nm = m;
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }
        // S->M
        ns = max(0, s - (M - m));
        nn = n;
        nm = min(M, s + m);
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }
        // N->S
        ns = min(S, s + n);
        nn = max(0, n - (S - s));
        nm = m;
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }

        // M->S
        ns = min(S, s + m);
        nn = n;
        nm = max(0, m - (S - s));
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }

        // N->M
        ns = s;
        nn = max(0, n - (M - m));
        nm = min(M, n + m);
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }
        // M->N
        ns = s;
        nn = min(N, n + m);
        nm = max(0, m - (N - n));
        if (!vis.count({ns, nn, nm})) {
            q.push({ns, nn, nm, step + 1});
            vis.insert({ns, nn, nm});
        }
    }
    return -1;
}
int main() {
    while (cin >> S >> N >> M) {
        if (S == 0 && N == 0 && M == 0) break;
        if (S % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        int res = bfs();
        if (res == -1) cout << "NO" << endl;
        else cout << res << endl;
    }
    return 0;
}
