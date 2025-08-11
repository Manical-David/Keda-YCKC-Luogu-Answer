#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }
    while (q--) {
        int d;
        cin >> d;
        int idx = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
        if (idx == k) {
            cout << b[k] << " ";
            continue;
        }
        if (a[idx] == d) {
            cout << b[idx] << " ";
            continue;
        }
        int a_pre = a[idx];
        int a_n = a[idx + 1];
        int b_pre = b[idx];
        int b_n = b[idx + 1];
        long long del = d - a_pre;
        long long t = b_pre + (del * (b_n - b_pre)) / (a_n - a_pre);
        cout << t << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}