#include <iostream>
using namespace std;

long long calc(long long N, long long x) {
    return (x + 1) * N + x * (x + 1) / 2;
}
int main() {
    long long N, K;
    cin >> N >> K;
    if (N >= K) {
        cout << 0 << '\n';
        return 0;
    }
    long long l = 0;
    long long r = 1e9;
    long long ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long tot = calc(N, mid);

        if (tot >= K) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
