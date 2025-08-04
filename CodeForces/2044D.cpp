#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 5;
long long t, vis[N], cnt, n, a[N];
void solve() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(vis[a[i]] == 1) cnt++;
        else {
            vis[a[i]] = 1;
            cout << a[i] << ' ';
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] != 1) cout << i << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}