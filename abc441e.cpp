// #include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace std;
// using ll = long long;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     string s;
//     cin >> n >> s;
//     vector<ll> pref(n + 1, 0);
//     for (int i = 0; i < n; i++) {
//         int d = (s[i] == 'A') ? 1 : (s[i] == 'B') ? -1
//                                                   : 0;
//         pref[i + 1] = pref[i] + d;
//     }
//     vector<ll> vals = pref;
//     sort(vals.begin(), vals.end());
//     vals.erase(unique(vals.begin(), vals.end()), vals.end());
//     int M = vals.size();
//     atcoder::fenwick_tree<ll> fw(M);
//     ll ans = 0;
//     for (int j = 0; j <= n; j++) {
//         int idx0 = int(lower_bound(vals.begin(), vals.end(), pref[j]) - vals.begin());
//         ans += fw.sum(idx0);
//         fw.add(idx0, 1);
//     }
//     cout << ans << '\n';
//     return 0;
// }
// ...existing code...
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
using ll = long long;
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, ll v=1) {
        for (int i = idx + 1; i <= n; i += i & -i) bit[i] += v;
    }
    ll sum(int r) {
        ll s = 0;
        for (int i = r; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int d = (s[i] == 'A') ? 1 : (s[i] == 'B') ? -1 : 0;
        pref[i + 1] = pref[i] + d;
    }
    vector<ll> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int M = vals.size();
    Fenwick fw(M);
    ll ans = 0;
    for (int j = 0; j <= n; j++) {
        int idx0 = int(lower_bound(vals.begin(), vals.end(), pref[j]) - vals.begin());
        ans += fw.sum(idx0);
        fw.add(idx0, 1);
    }
    cout << ans << '\n';
    return 0;
}