#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    long long T;
    if (!(cin >> N >> K >> T)) return 0;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long d, r;
        cin >> d >> r;
        if (r >= K * d) sum += r;
    }
    cout << (sum >= T ? "Yes\n" : "No\n");
    return 0;
}