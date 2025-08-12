#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8 + 1;
bitset<MAX> is_prime;
vector<int> primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((long long)i * i < MAX) {
                for (int j = i * i; j < MAX; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}
int main() {
    sieve();
    int n, q;
    scanf("%d %d", &n, &q);
    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", primes[k - 1]);
    }
    return 0;
}
