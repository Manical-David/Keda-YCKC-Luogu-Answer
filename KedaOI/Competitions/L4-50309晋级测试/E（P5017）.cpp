#include <bits/stdc++.h> // Copyright : Manical David
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g(n + 1);
    vector <int> vis;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 0) {
            vis.push_back(v);
        } 
        else {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    vector <int> d1(n + 1, INT_MAX);
    queue <int> q;
    d1[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d1[v] == INT_MAX) {
                d1[v] = d1[u] + 1;
                q.push(v);
            }
        }
    }
    vector <int> dn(n + 1, INT_MAX);
    dn[n] = 0;
    queue <int> qn;
    qn.push(n);
    while (!qn.empty()) {
        int u = qn.front();
        qn.pop();
        for (int v : g[u]) {
            if (dn[v] == INT_MAX) {
                dn[v] = dn[u] + 1;
                qn.push(v);
            }
        }
    }
    int C1 = INT_MAX;
    for (int v : vis) {
        if (d1[v] != INT_MAX) {
            if (d1[v] + 1 < C1) {
                C1 = d1[v] + 1;
            }
        }
    }
    int Cn = INT_MAX;
    for (int v : vis) {
        if (dn[v] != INT_MAX) {
            if (dn[v] + 1 < Cn) {
                Cn = dn[v] + 1;
            }
        }
    }
    int d1n = d1[n];
    for (int i = 1; i <= n; i++) {
        int a = min(d1[i], C1);
        int b = min(dn[i], Cn);
        int via_i = INT_MAX;
        if (a != INT_MAX && b != INT_MAX) {
            via_i = a + b;
        }
        int minn = min(d1n, via_i);
        if (minn == INT_MAX) {
            cout << -1;
        } 
        else {
            cout << minn;
        }
        if (i < n) {
            cout << " ";
        }
    }
    cout << '\n';
    return 0;
}
/*
# 今天的CSP-J炸了
如果去年我晋级了，我就能AK；
太悲惨了
我最后两题写了个O(n^3)的解法
考试的时候根本没有想到正解
*/