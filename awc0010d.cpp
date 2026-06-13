#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> H(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        sum += H[i];
    }
    if (K == 0) {
        cout << sum << '\n';
        return 0;
    }
    vector<ll> s(N);
    for (int i = 0; i < N; i++) {
        s[i] = H[i] - 1;
    }
    sort(s.rbegin(), s.rend());
    ll maxx = 0;
    for (int i = 0; i < K; i++) {
        maxx += s[i];
    }
    cout << sum - maxx << '\n';
    return 0;
}