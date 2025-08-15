#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e3 + 5;
int T, n, m, a[N], flag;
pair<int, int> b[N];
void solve() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    flag = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> a[j];
        sort(a + 1, a + 1 + m);
        b[i].first = a[1], b[i].second = i;
        for (int j = 2; j <= m; j++)
            if (a[j] != a[j - 1] + n)
                flag = 1;
    }
    if (flag) {
        cout << -1 << '\n';
        return ;
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        cout << b[i].second << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
