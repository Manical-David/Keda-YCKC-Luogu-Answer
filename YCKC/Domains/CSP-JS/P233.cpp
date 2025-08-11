#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
int main() {
    int K, M;
    cin >> K;
    vector<long long> fib(K);
    for (int i = 0; i < K; ++i) {
        cin >> fib[i];
    }
    cin >> M;
    if (M <= K) {
        cout << fib[M - 1] % MOD << endl;
        return 0;
    }
    fib.resize(M);
    for (int i = K; i < M; ++i) {
        long long sum = 0;
        for (int j = i - K; j < i; ++j) {
            sum += fib[j];
            sum %= MOD;
        }
        fib[i] = sum;
    }
    cout << fib[M-1] % MOD << endl;
    return 0;
}