#include <bits/stdc++.h>
using namespace std;
struct node {
    int d;
    int idx;
    node(int d = INT_MIN/2, int i = 0): d(d), idx(i) {}
};
bool check(node &a, node &b){
    if (a.d != b.d) return a.d > b.d;
    return a.idx > b.idx;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < N-1; ++i) {
        int A,B; cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int root = 1;
    vector<int> par(N+1, -1), ord;
    ord.reserve(N);
    stack<int> st; // BFS
    st.push(root);
    par[root] = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        ord.push_back(u);
        for (int v: adj[u]){
            if (par[v] == -1){
                par[v] = u;
                st.push(v);
            }
        }
    }
    vector<node> bd(N+1);
    for (int i = (int)ord.size()-1; i >= 0; --i){
        int u = ord[i];
        // self
        bd[u] = node(0, u);
        for (int v: adj[u]){
            if (v == par[u]) continue;
            node cd = bd[v];
            cd.d += 1;
            if (check(cd, bd[u])) bd[u] = cd;
        }
    }
    vector<node> bu(N+1, node(INT_MIN/2, 0));
    for (int u: ord){
        node top1(INT_MIN/2, 0); int src1 = -1;
        node top2(INT_MIN/2, 0); int src2 = -1;
        node cd0(0, u);
        top1 = cd0; src1 = 0;
        for (int v: adj[u]){
            if (v == par[u]) continue;
            node cd = bd[v];
            node cdu(cd.d + 1, cd.idx);
            int src = v;
            if (check(cdu, top1)){
                top2 = top1; src2 = src1;
                top1 = cdu; src1 = src;
            } else if (check(cdu, top2)){
                top2 = cdu; src2 = src;
            }
        }
        if (check(bu[u], top1)){
            top2 = top1; src2 = src1;
            top1 = bu[u]; src1 = par[u]; 
        } else if (check(bu[u], top2)){
            top2 = bu[u]; src2 = par[u];
        }
        for (int v: adj[u]){
            if (v == par[u]) continue;
            node use(INT_MIN/2, 0);
            if (src1 == v){
                use = top2;
            } else {
                use = top1;
            }
            node cnd_p;
            if (use.d <= INT_MIN/4) cnd_p = node(INT_MIN/2, 0);
            else cnd_p = node(use.d + 1, use.idx);
            node upc;
            if (bu[u].d <= INT_MIN/4) upc = node(INT_MIN/2,0);
            else upc = node(bu[u].d + 1, bu[u].idx);
            node cur = cnd_p;
            if (check(upc, cur)) cur = upc;
            bu[v] = cur;
        }
    }
    for (int v = 1; v <= N; ++v){
        node ans = bd[v];
        if (check(bu[v], ans)) ans = bu[v];
        cout << ans.idx << '\n';
    }
    return 0;
}