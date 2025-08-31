#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n - 1; ++i) {
        if(a[i] < a[i-1] && a[i] < a[i+1]) {
            ans++;
        }
        else if(a[i] == a[i-1] && a[i] < a[i+1]) {
            if(i == 1 || a[i-2] > a[i-1]) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}