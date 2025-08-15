#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int maxx = 0;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        maxx = max(maxx, a[i] + n - i);
    }
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] + n >= maxx) ans++;
        else break;
    }
    cout << ans << '\n';
    return 0;
}