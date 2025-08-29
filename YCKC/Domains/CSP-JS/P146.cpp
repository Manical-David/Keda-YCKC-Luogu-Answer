#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long moy[45];
vector<long long> a, b;
void dfs(int st, int en, long long sum, vector<long long> &now) {
    if (sum > m)
        return;
    if (st > en) {
        now.push_back(sum);
        return;
    }
    dfs(st + 1, en, sum + moy[st], now);
    dfs(st + 1, en, sum, now);
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> moy[i];
    dfs(1, n / 2, 0, a);
    dfs(n / 2 + 1, n, 0, b);
    sort(a.begin(), a.end());
    long long ans = 0;
    int lenb = b.size();
    for (int i = 0; i < lenb; i++)
        ans += upper_bound(a.begin(), a.end(), m - b[i]) - a.begin();
    cout << ans << '\n';
    return 0;
}