#include <bits/stdc++.h>
using namespace std;
int N, sum;
vector<int> g;
vector<bool> st;
bool dfs(int idx, int len, int tar, int cnt) {
    if (cnt == N) return true; // 所有木棍都用完了
    int prev = -1;
    for (int i = idx; i < N; ++i) {
        if (st[i] || g[i] == prev) continue;
        if (len + g[i] > tar) continue;
        st[i] = true;
        if (len + g[i] == tar) {
            if (dfs(0, 0, tar, cnt + 1)) return true;
        } else {
            if (dfs(i + 1, len + g[i], tar, cnt + 1)) return true;
        }
        st[i] = false;
        prev = g[i];
        // 剪枝
        if (len == 0) break;
    }
    return false;
}
int main() {
    cin >> N;
    g.resize(N);
    sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> g[i];
        sum += g[i];
    }
    sort(g.rbegin(), g.rend());
    for (int len = g[0]; len <= sum; ++len) {
        if (sum % len != 0) continue;
        st.assign(N, false);
        if (dfs(0, 0, len, 0)) {
            cout << len << endl;
            break;
        }
    }
    return 0;
}