#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int a[200005];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i != 1) a[i] = min(a[i], a[i - 1]);
    }
    while(m--) {
        int x;
        cin >> x;
        int l = 1, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(a[mid] <= x) r = mid;
            else l = mid + 1;
        }
        if(a[r] <= x) cout << r << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}