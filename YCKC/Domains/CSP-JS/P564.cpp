#include <bits/stdc++.h>
using namespace std;
long long countZeros(long long n) {
    long long cnt = 0;
    while (n > 0) {
        n /= 5;
        cnt += n;
    }
    return cnt;
}
long long Minnn(long long k) {
    if (k == 0) return 0;
    long long low = 1;
    long long high = 5 * k;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long zeros = countZeros(mid);
        if (zeros >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    long long k;
    cin >> k;
    cout << Minnn(k) << '\n';
    return 0;
}