#include <bits/stdc++.h>
using namespace std;
struct F {
    int n;
    vector<int> f;
    F(int n = 0) : n(n), f(n + 1, 0) {}
    void a(int i, int v) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    int s(int i) {
        int r = 0;
        for (; i > 0; i -= i & -i)
            r += f[i];
        return r;
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1, -1), a(m), b(m);
    const int I = 1000000000;
    vector<int> p(n + 1, I);
    int e = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[e] = v;
        b[e] = h[u];
        h[u] = e;
        if (u < p[v])
            p[v] = u;
        e++;
    }
    vector<int> d(n + 1, I);
    d[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({1, 1});
    while (!q.empty())
    {
        auto [w, u] = q.top();
        q.pop();
        if (w != d[u])
            continue;
        for (int i = h[u]; i != -1; i = b[i])
        {
            int v = a[i];
            int z = w > v ? w : v;
            if (z < d[v])
            {
                d[v] = z;
                q.push({z, v});
            }
        }
    }
    vector<vector<int>> s(n + 2);
    for (int v = 1; v <= n; v++)
        if (p[v] != I)
            s[p[v]].push_back(v);
    F f(n);
    int t = 0;
    int r = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int v : s[k])
        {
            f.a(v, 1);
            t++;
        }
        if (d[k] > r)
            r = d[k];
        if (r > k)
            cout << -1 << "\n";
        else
            cout << (t - f.s(k)) << "\n";
    }
    return 0;
}