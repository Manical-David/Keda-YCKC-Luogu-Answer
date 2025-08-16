#include <bits/stdc++.h>
using namespace std;
bool check(const vector<int>& a, int n, int k, long long t) {
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > t) {
            total += (a[i] - t + k - 2) / (k - 1); // Equivalent to ceil((a[i] - t) / (k - 1))
            if (total > t) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, k;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    if (k == 1) {
        printf("%d\n", *max_element(a.begin(), a.end()));
        return 0;
    }
    long long l = 1;
    long long r = *max_element(a.begin(), a.end());
    long long ans = r;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(a, n, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}