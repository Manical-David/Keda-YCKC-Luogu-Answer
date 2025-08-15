#include <bits/stdc++.h>
using namespace std;
struct node {
    int d;
    int w;
    int p;
};
bool cmp(const node &a, const node &b) {
    return (a.p + (1000000 - a.d)) < (b.p + (1000000 - b.d));
}
int main() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<node> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].d >> a[i].w >> a[i].p;
    }
    sort(a.begin(), a.end(), cmp);
    long long ans = 0;
    int tong = L;
    for (const auto &it : a) {
        if (tong <= 0) break;
        int buy = min(tong, it.w);
        ans += buy * (it.p + (m - it.d));
        tong -= buy;
    }
    cout << ans << '\n';
    return 0;
}