#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    unordered_set<long long> seet;
    for (int i = 0; i <= n; ++i) {
        long long val = sum[i] % m;
        if (val < 0) {
            val += m;
        }
        if (seet.count(val)) {
            cout << "YES" << endl;
            return 0;
        }
        seet.insert(val);
    }
    
    cout << "NO" << endl;
    return 0;
}
