#include <bits/stdc++.h>
using namespace std;
constexpr int N = 27;
int n, v, weight[N], w[N];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    // freopen("testin.in", "r", stdin);
    // freopen("testout.out", "w", stdout);
    cin >> n >> v;
    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> w[i];
    }
    int minn = 100;
    for(int i = 0; i < (1 << n); i++) {
        int t = 0, tmpv = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                t += w[j];
                tmpv += weight[j];
            }
        }
        if(tmpv <= v) {
            minn = min(minn, abs(100 - t));
        }
    }
    int res = 0;
    for(int i = 0; i < (1 << n); i++) {
        int t = 0, tmpv = 0, cnt = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                t += w[j];
                tmpv += weight[j];
                cnt++;
            }
        }
        if(tmpv <= v && abs(100 - t) == minn) {
            res = max(res, cnt);
        }
    }
    cout << res << '\n';
    return 0;
}
