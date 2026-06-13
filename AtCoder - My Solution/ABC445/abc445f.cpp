#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& qrs) {
        vector<vector<int>> g(n);
        for (auto &e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        vector<int> tin(n), tout(n), dep(n), inp(n);
        int timer = 0;
        int LOG = 1; while ((1 << LOG) <= n) ++LOG;
        vector<vector<int>> up(n, vector<int>(LOG, -1));
        function<void(int,int)> dfs = [&](int u, int p) {
            tin[u] = ++timer;
            up[u][0] = p;
            dep[u] = (p == -1 ? 0 : dep[p] + 1);
            int mask = 1 << (s[u] - 'a');
            inp[u] = (p == -1 ? mask : (inp[p] ^ mask));
            for (int v : g[u]) if (v != p) dfs(v, u);
            tout[u] = timer;
        };
        dfs(0, -1);
        for (int k = 1; k < LOG; ++k)
            for (int v = 0; v < n; ++v)
                up[v][k] = (up[v][k-1] == -1 ? -1 : up[ up[v][k-1] ][k-1]);

        auto lca = [&](int a, int b) {
            if (dep[a] < dep[b]) swap(a, b);
            int diff = dep[a] - dep[b];
            for (int k = 0; k < LOG; ++k) if (diff & (1 << k)) a = up[a][k];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; --k)
                if (up[a][k] != up[b][k]) { a = up[a][k]; b = up[b][k]; }
            return up[a][0];
        };
        struct Fenwick {
            int n; vector<int> bit;
            Fenwick(int n=0): n(n), bit(n+1, 0) {}
            void add(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] ^= val; }
            void range_xor(int l, int r, int val) { if (l > r) return; add(l, val); if (r + 1 <= n) add(r + 1, val); }
            int point(int idx) { int r = 0; for (; idx > 0; idx -= idx & -idx) r ^= bit[idx]; return r; }
        } fw(n);
        auto sunv = qrs;
        vector<bool> ans;
        ans.reserve(qrs.size());
        for (const auto &qr : qrs) {
            if (qr[0] == 'u') {
                size_t p1 = qr.find(' ');
                size_t p2 = qr.find(' ', p1 + 1);
                int ui = stoi(qr.substr(p1 + 1, p2 - p1 - 1));
                char c = qr[p2 + 1];
                if (s[ui] == c) continue;
                int delt = (1 << (s[ui] - 'a')) ^ (1 << (c - 'a'));
                s[ui] = c;
                fw.range_xor(tin[ui], tout[ui], delt);
            } else {
                size_t p1 = qr.find(' ');
                size_t p2 = qr.find(' ', p1 + 1);
                int ui = stoi(qr.substr(p1 + 1, p2 - p1 - 1));
                int vi = stoi(qr.substr(p2 + 1));
                int anc = lca(ui, vi);
                int cur_u = inp[ui] ^ fw.point(tin[ui]);
                int cur_v = inp[vi] ^ fw.point(tin[vi]);
                int Amask = 1 << (s[anc] - 'a');
                int pmask = cur_u ^ cur_v ^ Amask;
                ans.push_back((pmask & (pmask - 1)) == 0);
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    return 0;
}