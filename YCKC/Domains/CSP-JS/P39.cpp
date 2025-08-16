#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005], n, m, k;
bool ch(long long x) {
    long long int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] * b[m] <= x)
            continue;
        if (a[i] * b[1] > x) {
            cnt += m;
            continue;
        }
        long long l = 1, r = m, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (a[i] * b[mid] > x)
                r = mid;
            else
                l = mid + 1;
        }
        cnt += m - r + 1;
    }
    return cnt < k;
}
int main() {
    cin >> n >> m;
    cin >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    long long int l = a[1] * b[1], r = a[n] * b[m], mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (ch(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
    return 0;
}