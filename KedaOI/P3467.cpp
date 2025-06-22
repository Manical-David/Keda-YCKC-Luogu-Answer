#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, m, d[N];
vector<int> g[N];
bool topSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }
    vector<int> res;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        res.push_back(t);
        for (const auto &it : g[t]) {
            d[it] -= 1;
            if (d[it] == 0) {
                q.push(it);
            }
        }
    }

    return (int)res.size() == n;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        d[v] += 1;
    }
    vector<int> res;
    int t;
    while (scanf("%d", &t) != EOF) res.push_back(t);
    if ((int)res.size() == 1 && n != 1) {
        if (res[0] == -1 && !topSort()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        set<int> st(res.begin(), res.end());
        if (st.size() != n || (int)res.size() != n) {
            printf("No\n");
        } else {
            for (int i = 0; i < n; i++) {
                if (res[i] > n || res[i] < 1 || d[res[i]] > 0) {
                    printf("No\n");
                    return 0;
                }
                for (const auto &it : g[res[i]]) {
                    d[it] -= 1;
                }
            }
            printf("Yes\n");
        }
    }
    return 0;
}