#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int N, Q;
    cin >> N >> Q;
    vector<long long> E(N);
    for (int i = 0; i < N; ++i) {
        cin >> E[i];
    }
    sort(E.begin(), E.end());
    vector<long long> p(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        p[i] = p[i - 1] + E[i - 1];
    }
    while (Q--) {
        long long X;
        cin >> X;
        int k = upper_bound(p.begin(), p.end(), X) - p.begin() - 1;
        cout << k << '\n';
    }
    return 0;
}