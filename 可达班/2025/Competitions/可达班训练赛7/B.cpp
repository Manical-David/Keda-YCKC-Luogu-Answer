#include <bits/stdc++.h>
using namespace std;
struct companies {
    vector <int> workers;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    companies a, b, c, d;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            int t;
            cin >> t;
            if(j == 0) {
                a.workers.push_back(t);
            }
            else if(j == 1) {
                b.workers.push_back(t);
            }
            else if(j == 2) {
                c.workers.push_back(t);
            }
            else if(j == 3) {
                d.workers.push_back(t);
            }
        }
    }
    sort(a.workers.begin(), a.workers.end());
    sort(b.workers.begin(), b.workers.end());
    sort(c.workers.begin(), c.workers.end());
    sort(d.workers.begin(), d.workers.end());
    unordered_map<int, int> ab_sum;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ab_sum[a.workers[i] + b.workers[j]]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cd = c.workers[i] + d.workers[j];
            if (ab_sum.count(-cd)) {
                ans += ab_sum[-cd];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}