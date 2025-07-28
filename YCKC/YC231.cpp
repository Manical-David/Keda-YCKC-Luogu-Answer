#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N+1);
    for(int i = 1; i <= N; ++i) cin >> A[i];
    vector<ll> S(N), T(N);
    for(int i = 1; i < N; ++i) cin >> S[i] >> T[i];
    for(int i = 1; i < N; ++i) {
        ll cnt = A[i] / S[i];
        if(cnt > 0) {
            A[i] -= cnt * S[i];
            A[i+1] += cnt * T[i];
        }
    }
    cout << A[N] << '\n';
    return 0;
}