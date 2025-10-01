#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector <vector<int> > vis;
vector<int> c0, c1;
int k_max;
int dfs(int k, int v_prev) {
    if (k == k_max) {
        return v_prev;
    }
    if (vis[k][v_prev] != -1) {
        return vis[k][v_prev];
    }
    int minn = INF;
    for (int v_curr : {0, 1}) {
        int op2 = (v_prev + v_curr) % 2;
        int t = v_prev ^ v_curr;
        int op1 = (t == 0) ? c1[k] : c0[k];
        int sub = dfs(k + 1, v_curr);
        minn = min(minn, op2 + op1 + sub);
    }
    vis[k][v_prev] = minn;
    return minn;
}
int main() {
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    int s_len = n - m;
    if (s_len <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    k_max = n / m;
    c0.resize(k_max + 2, 0);
    c1.resize(k_max + 2, 0);
    for (int k = 1; k <= k_max - 1; ++k) {
        int si = (k - 1) * m;
        int ei = k * m - 1;
        ei = min(ei, s_len - 1);
        if (si > ei) continue;
        int cnt0 = 0, cnt1 = 0;
        for (int i = si; i <= ei; ++i) {
            int j = i + m;
            int a = (s[i] == '1') ? 1 : 0;
            int b = (s[j] == '1') ? 1 : 0;
            int t = a ^ b;
            if (t == 0) cnt0++;
            else cnt1++;
        }
        c0[k] = cnt0;
        c1[k] = cnt1;
    }
    vis.assign(k_max + 2, vector<int>(2, -1));
    int ans = min(dfs(1, 0), dfs(1, 1));
    cout << ans << '\n';
    return 0;
}