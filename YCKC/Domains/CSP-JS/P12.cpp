#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> d(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int s, e, h;
        cin >> s >> e >> h;
        d[s - 1] += h;
        if (e < n) {
            d[e] -= h;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            d[i] += d[i - 1];
        }
        a[i] += d[i];
    }
    int s, e;
    cin >> s >> e;
    long long sum = 0;
    for (int i = s - 1; i < e; ++i) {
        sum += a[i];
    }
    cout << sum << '\n';
    return 0;
}