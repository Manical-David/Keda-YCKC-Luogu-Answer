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
/*
因为放完后每张牌一定比下面的大，每张牌的点数又是 0,1,2,…,n×m−1，所以放牌一定是按照 0,1,2,…,n×m−1 的顺序放的。
因为是 n 头奶牛轮流放牌，所以设每头奶牛最小的牌为 t_i，则这头奶牛依次放的牌就是t_i,t_i+n,t_i+n×2,…,t_i+n×(m−1)。
对每一头奶牛的牌从小到大排序，然后判断每张牌之间差值是否都是 n。如果有不满足差值为 n 的，则无解。
若有解，则 t_i=0 的牛先放，t_i=1 的牛第二个放，以此类推。按照 t_i排序，输出排序后的原下标就是顺序。
*/