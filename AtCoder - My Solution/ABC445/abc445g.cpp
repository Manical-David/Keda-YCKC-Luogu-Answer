#include <bits/stdc++.h>
using namespace std;
struct node {
    int ci, cj;
    int oi, oj;
};
vector<string> G, OU;
int N;
static inline long long keyIJ(int i, int j) {
    return ( (long long)i << 32 ) | (unsigned)j;
}
void solve_sub(int A, int B, const vector<node> &nodes) {
    if (nodes.empty()) return;
    if ((A % 2 == 0) && (B % 2 == 0)) {
        array<vector<node>,4> fps;
        for (const auto &nd : nodes) {
            int r = nd.ci & 1, c = nd.cj & 1;
            node nn = nd;
            nn.ci >>= 1;
            nn.cj >>= 1;
            fps[r*2 + c].push_back(nn);
        }
        for (int t = 0; t < 4; ++t) solve_sub(A/2, B/2, fps[t]);
        return;
    }
    int M = (int)nodes.size();
    unordered_map<long long,int> pos2id;
    pos2id.reserve(M * 2);
    for (int i = 0; i < M; ++i) pos2id[keyIJ(nodes[i].ci, nodes[i].cj)] = i;
    bool bo = (A % 2 == 1 && B % 2 == 1);
    vector<int> leftId(M, -1), rightId(M, -1), lnode, rnode;
    lnode.reserve(M); rnode.reserve(M);
    for (int i = 0; i < M; ++i) {
        bool fl;
        if (bo) fl = (nodes[i].ci & 1) == 0;
        else         fl = ((nodes[i].ci + nodes[i].cj) & 1) == 0; 
        if (fl) { leftId[i] = (int)lnode.size(); lnode.push_back(i); }
        else        { rightId[i] = (int)rnode.size(); rnode.push_back(i); }
    }
    int L = (int)lnode.size(), R = (int)rnode.size();
    if (M == 0) return;
    vector<pair<int,int>> offsts;
    offsts.reserve(8);
    unordered_set<long long> offs; offs.reserve(8);
    auto addOff = [&](int dx, int dy){
        long long k = keyIJ(dx, dy);
        if (offs.insert(k).second) offsts.emplace_back(dx, dy);
    };
    int d[2] = {A, B};
    for (int t = 0; t < 2; ++t) {
        int dx0 = d[t], dy0 = d[1-t];
        for (int sx : {-1, 1}) for (int sy : {-1, 1}) addOff(sx*dx0, sy*dy0);
    }
    vector<vector<int>> adj(L);
    for (int li = 0; li < L; ++li) {
        int idx = lnode[li];
        int ci = nodes[idx].ci, cj = nodes[idx].cj;
        auto &vec = adj[li];
        for (auto &off : offsts) {
            int ni = ci + off.first, nj = cj + off.second;
            long long k = keyIJ(ni, nj);
            auto it = pos2id.find(k);
            if (it == pos2id.end()) continue;
            int nid = it->second;
            if (rightId[nid] != -1) vec.push_back(rightId[nid]);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    vector<int> pairU(L, -1), pairV(R, -1), dist(L);
    auto bfs = [&]() -> bool {
        queue<int> q;
        fill(dist.begin(), dist.end(), -1);
        for (int u = 0; u < L; ++u) if (pairU[u] == -1) { dist[u] = 0; q.push(u); }
        bool flag = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (pairV[v] != -1 && dist[pairV[v]] == -1) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
                if (pairV[v] == -1) flag = true;
            }
        }
        return flag;
    };
    function<bool(int)> dfs = [&](int u)->bool {
        for (int v : adj[u]) {
            if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    };
    int cnt = 0;
    while (bfs()) {
        for (int u = 0; u < L; ++u) if (pairU[u] == -1) if (dfs(u)) ++cnt;
    }
    vector<char> lv(L, 0), rvis(R, 0);
    queue<int> q;
    for (int u = 0; u < L; ++u) if (pairU[u] == -1) { lv[u] = 1; q.push(u); }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (rvis[v]) continue;
            if (pairU[u] == v) continue;
            rvis[v] = 1;
            int uu = pairV[v];
            if (uu != -1 && !lv[uu]) { lv[uu] = 1; q.push(uu); }
        }
    }
    for (int i = 0; i < M; ++i) {
        if (leftId[i] != -1) {
            if (lv[leftId[i]]) {
                OU[nodes[i].oi][nodes[i].oj] = 'o';
            }
        } else {
            if (!rvis[rightId[i]]) {
                OU[nodes[i].oi][nodes[i].oj] = 'o';
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int A, B;
    if (!(cin >> N >> A >> B)) return 0;
    G.resize(N);
    for (int i = 0; i < N; ++i) cin >> G[i];
    OU = G;
    vector<node> st;
    st.reserve(N * N / 2);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        if (G[i][j] == '.') st.push_back({i, j, i, j});
    }
    solve_sub(A, B, st);
    for (int i = 0; i < N; ++i) cout << OU[i] << '\n';
    return 0;
}