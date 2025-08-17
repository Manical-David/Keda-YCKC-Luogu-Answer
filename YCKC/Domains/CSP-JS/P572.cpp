#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    long long p, q, r;
    cin >> n >> p >> q >> r;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + a[i - 1];
    }
    unordered_map<long long, int> s_map;
    for (int i = 0; i <= n; ++i) {
        s_map[S[i]] = i;
    }
    for (int x = 0; x <= n; ++x) {
        long long y_tar = S[x] + p;
        auto it_y = s_map.find(y_tar);
        if (it_y == s_map.end()) {
            continue;
        }
        long long z_tar = y_tar + q;
        auto it_z = s_map.find(z_tar);
        if (it_z == s_map.end()) {
            continue;
        }
        long long w_tar = z_tar + r;
        if (s_map.count(w_tar)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}