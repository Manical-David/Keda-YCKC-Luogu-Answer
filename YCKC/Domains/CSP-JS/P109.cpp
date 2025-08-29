#include <bits/stdc++.h>
using namespace std;
const int N = 100;
long long mem[N + 1];
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
long long calc(int x) {
    if (mem[x] != 0) return mem[x];
    if (x == 1) return 1;
    if (is_prime(x)) return x;
    vector<int> facs;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            facs.push_back(i);
        }
    }
    long long ans = 1;
    for (int fac : facs) {
        ans *= calc(fac);
    }
    return mem[x] = ans;
}
int main() {
    memset(mem, 0, sizeof(mem));
    mem[1] = 1;
    int n;
    cin >> n;
    cout << calc(n) << endl;
    return 0;
}