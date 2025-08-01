#include <bits/stdc++.h>
using namespace std;
long long sum[1000005];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    if(k >= n - 1) {
        cout << 0;
        return 0;
    }
    long long ma = 0;
    for(int i = 1; i + k < n; i++) {
        ma = max(sum[i + k] - sum[i], ma);
    }
    cout << sum[n - 1] - ma;
    return 0;
}