#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N + 1), ans(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = N; i >= 1; --i) {
        ans[i] = (A[i] == i) ? i : ans[A[i]];
    }
    for (int i = 1; i <= N; ++i) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}