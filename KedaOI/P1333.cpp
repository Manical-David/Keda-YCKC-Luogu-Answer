#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7, M = 4e5 + 7;
int head[N], e[M], ne[M], idx = 0;
void init() {
    memset(head, -1, sizeof(head));
    idx = 0;
}
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx;
    idx += 1;
}
int type, n, m;
vector <int> path;
bool st[M];
int din[N], dout[N];
bool vis[N];
void dfs2(int u) {
    vis[u] = true;
    for(int i = head[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if(!vis[v]) dfs2(v);
    }
}
void dfs(int u) {
    for(int &i = head[u]; i != -1;) {
        if(st[i]) {
            i = ne[i];
            continue;
        }
        st[i] = true;
        if(type == 1) st[i ^ 1] = true;
        int t;
        if(type == 1) {
            t = i / 2 + 1;
            if(i & 1) t = -t;
        }
        else {
            t = i + 1;
        }
        int j = e[i];
        i = ne[i];
        dfs(j);
        path.push_back(t);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> type;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        if(type == 1) add(b, a);
        din[b] += 1, dout[a] += 1;
    }
    int start = -1;
    for(int i = 1; i <= n; i++) {
        if(head[i] != -1) {
            start = i;
            break;
        }
    }
    if(start == -1) {
        cout << "YES\n";
        return 0;
    }
    dfs2(start);
    for(int i = 1; i <= n; i++) {
        if((din[i] + dout[i]) && !vis[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    dfs(start);
    if((int)path.size() < m) {
        cout << "NO\n";
        return 0;
    }
    if(type == 1) {
        for(int i = 1; i <= n; i++) {
            if((din[i] + dout[i]) & 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(din[i] != dout[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(head[i] != -1) {
            dfs(i);
            break;
        }
    }
    if((int)path.size() < m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    reverse(path.begin(), path.end());
    for(const auto &it : path) {
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}