#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> cnt;
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += cnt[-a[j]];
        cnt[a[j]]++;
    }
    cout << ans << endl;
    return 0;
}