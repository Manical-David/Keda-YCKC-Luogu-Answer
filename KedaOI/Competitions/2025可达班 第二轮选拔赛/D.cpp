#include <bits/stdc++.h>
using namespace std;
int n, l, t, k, m;
vector<int> w;
vector<unordered_set<int>> c;
unordered_set<int> Mset;
int must_sum = 0;
int res = 0;
void dfs(int pos, int ans, unordered_set<int>& chosed, const vector<int>& chose) {
    if (ans > t) return; // 剪枝：当前和已经超过上限
    if (pos == chose.size()) {
        if (ans >= l && ans <= t) {
            res++;
        }
        return;
    }
    // 不选
    dfs(pos + 1, ans, chosed, chose);
    // 选
    int food = chose[pos];
    bool checked = true;
    for (int f : chosed) {
        if (c[f].count(food)) {
            checked = false;
            break;
        }
    }
    if (checked) {
        chosed.insert(food);
        dfs(pos + 1, ans + w[food - 1], chosed, chose);
        chosed.erase(food);
    }
}
int main() {
    cin >> n >> l >> t;
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    cin >> k;
    c.resize(n + 1);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        c[x].insert(y);
        c[y].insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        Mset.insert(b);
        must_sum += w[b - 1];
    }
    // 检查冲突
    for (int f1 : Mset) {
        for (int f2 : Mset) {
            if (f1 < f2 && c[f1].count(f2)) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    // 候选食物
    vector<int> chose;
    for (int i = 1; i <= n; ++i) {
        if (Mset.count(i)) continue;
        bool able = true;
        for (int f : Mset) {
            if (c[f].count(i)) {
                able = false;
                break;
            }
        }
        if (able) {
            chose.push_back(i);
        }
    }
    unordered_set<int> chosed;
    dfs(0, must_sum, chosed, chose);
    cout << res << endl;
    return 0;
}
// 发现写错了❌