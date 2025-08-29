#include <bits/stdc++.h>
using namespace std;
bool check(const vector<int>& x, int n, int c, int d) {
    int cnt = 1;
    int last_pos = x[0];
    for (int i = 1; i < n; ++i) {
        if (x[i] - last_pos >= d) {
            cnt++;
            last_pos = x[i];
            if (cnt >= c) {
                return true;
            }
        }
    }
    return cnt >= c;
}
int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x.begin(), x.end());
    int l = 0, r = x[n-1] - x[0];
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(x, n, c, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}