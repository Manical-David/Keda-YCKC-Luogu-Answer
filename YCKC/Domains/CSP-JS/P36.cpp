#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll mid, vector<ll> A, ll K) {
    ll sum = 0;
    for (ll a : A) {
        sum += min(a, mid);
    }
    return sum >= mid * K;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0) , cout.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll l = 0, r = accumulate(A.begin(), A.end(), 0LL) / K;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid, A, K)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
