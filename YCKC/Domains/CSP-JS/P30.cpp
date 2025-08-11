#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < N; ++i) {
        if (cur + A[i] > M) {
            ans++;
            cur = A[i];
        } else {
            cur += A[i];
        }
    }
    if (cur > 0) {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}