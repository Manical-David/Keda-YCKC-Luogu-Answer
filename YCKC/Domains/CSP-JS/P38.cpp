#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    while (Q--) {
        long long K;
        cin >> K;
        long long l = 0, r = N - 1;
        long long ans = -1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (A[mid] - mid - 1 < K) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans == -1) {
            cout << K << '\n';
        } else {
            cout << A[ans] + (K - (A[ans] - ans - 1)) << '\n';
        }
    }
    return 0;
}