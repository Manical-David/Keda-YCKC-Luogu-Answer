#include <bits/stdc++.h>
using namespace std;
int x;
constexpr int N = 2e5;
int sum[N], a[N];
bool check(int n) {
    return sum[n] >= x;
}
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        while(q--) {
            cin >> x;
            int l = 1, r = n + 1;
            while(l < r) {
                int mid = (l + r) / 2;
                if(check(mid)) r = mid;
                else l = mid + 1;
            }
            if(r == n + 1) cout << -1 << '\n';
            else cout << r << '\n';
        }
    }   
    return 0;
}