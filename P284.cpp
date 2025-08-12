
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e7;
vector<long long> primes;
void sieve() {
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
map<long long, int> checker(long long x) {
    map<long long, int> a;
    for (long long p : primes) {
        if (p * p > x) break;
        while (x % p == 0) {
            a[p]++;
            x /= p;
        }
    }
    if (x > 1) {
        a[x]++;
    }
    return a;
}
int main() {
    sieve();
    long long x;
    cin >> x;
    map<long long, int> a = checker(x);
    long long ans = 1;
    for (auto &[p, cnt] : a) {
        ans = (ans * (cnt + 1)) % MOD;
    }

    cout << ans << '\n';
    return 0;
}