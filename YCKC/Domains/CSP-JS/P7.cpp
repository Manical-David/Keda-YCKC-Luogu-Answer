#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int N, K;
    cin >> N >> K;
    long long sum = 0;
    int cnt = 0;
    unordered_map<int, int> hax;
    hax[0] = 1;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sum += num;
        int mod = sum % K;
        cnt += hax[mod];
        hax[mod]++;
    }
    cout << cnt << endl;
    return 0;
}
