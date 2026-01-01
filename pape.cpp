#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sz;
    int v[2];
    int c[2];
    Node(){ sz = 0; v[0]=v[1]=0; c[0]=c[1]=0; }
};

int n;
vector<int> a;
vector<Node> seg;

Node mergeNode(const Node &A, const Node &B) {
    Node R;
    pair<int,int> tmp[4];
    int tsz = 0;
    for (int i = 0; i < A.sz; ++i) tmp[tsz++] = {A.v[i], A.c[i]};
    for (int i = 0; i < B.sz; ++i) tmp[tsz++] = {B.v[i], B.c[i]};
    if (tsz == 0) return R;
    // combine duplicates
    pair<int,int> items[4];
    int isz = 0;
    for (int i = 0; i < tsz; ++i) {
        int val = tmp[i].first, cnt = tmp[i].second;
        bool found = false;
        for (int j = 0; j < isz; ++j) {
            if (items[j].first == val) { items[j].second += cnt; found = true; break; }
        }
        if (!found) items[isz++] = {val, cnt};
    }
    // reduce until size <= 2
    while (isz > 2) {
        int mn = INT_MAX;
        for (int i = 0; i < isz; ++i) mn = min(mn, items[i].second);
        int nsz = 0;
        for (int i = 0; i < isz; ++i) {
            int nc = items[i].second - mn;
            if (nc > 0) items[nsz++] = {items[i].first, nc};
        }
        isz = nsz;
    }
    R.sz = isz;
    for (int i = 0; i < isz; ++i) { R.v[i] = items[i].first; R.c[i] = items[i].second; }
    return R;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].sz = 1;
        seg[idx].v[0] = a[l];
        seg[idx].c[0] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
    seg[idx] = mergeNode(seg[idx<<1], seg[idx<<1|1]);
}

Node querySeg(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return Node();
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) >> 1;
    Node left = querySeg(idx<<1, l, mid, ql, qr);
    Node right = querySeg(idx<<1|1, mid+1, r, ql, qr);
    return mergeNode(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int q;
        cin >> n >> q;
        a.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        unordered_map<int, vector<int>> pos;
        pos.reserve(n*2);
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
        seg.assign(4*(n+5), Node());
        build(1, 1, n);
        while (q--) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            int thr = len / 3;
            Node cand = querySeg(1, 1, n, l, r);
            vector<int> ans;
            for (int i = 0; i < cand.sz; ++i) {
                int val = cand.v[i];
                auto &vec = pos[val];
                int cnt = int(upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l));
                if (cnt > thr) ans.push_back(val);
            }
            if (ans.empty()) {
                cout << -1 << '\n';
            } else {
                sort(ans.begin(), ans.end());
                for (size_t i = 0; i < ans.size(); ++i) {
                    if (i) cout << ' ';
                    cout << ans[i];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}