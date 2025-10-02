#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    int pos[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int minn = pos[1];
    int maxx = pos[1];
    string ans;
    ans.push_back('1');
    for (int m = 2; m <= n; ++m) {
        minn = min(minn, pos[m]);
        maxx = max(maxx, pos[m]);
        if (maxx - minn + 1 == m) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}