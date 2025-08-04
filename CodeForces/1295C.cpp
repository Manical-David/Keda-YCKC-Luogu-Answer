#include <bits/stdc++.h>
using namespace std;
int T, cnt = 0;
bool vis[300];
string s, t;
vector<int> v[300];
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(vis, false, sizeof vis);
        for (char i = 'a'; i <= 'z'; ++i)
            v[i].clear();
        cnt = 1;
        cin >> s >> t;
        int n = s.length(), m = t.length();
        s = " " + s, t = " " + t;
        for (int i = 1; i <= n; ++i) {
            vis[s[i]] = true;
            v[s[i]].push_back(i);
        }
        bool flag = false;
        for (int i = 1; i <= m; ++i) {
            if (!vis[t[i]]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            printf("-1\n");
            continue;
        }
        int lst = 0;
        for (int i = 1; i <= m; ++i) {
            int it = upper_bound(v[t[i]].begin(), v[t[i]].end(), lst) - v[t[i]].begin();
            if (it >= v[t[i]].size())
                lst = v[t[i]][0], ++cnt;
            else
                lst = v[t[i]][it];
        }
        printf("%d\n", cnt);
    }
    return 0;
}