#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxx = 0, minn = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(minn < a[i]) maxx = max(maxx, a[i] - minn);
        minn = min(minn, a[i]);
    }
    cout << maxx << '\n';
    return 0;
}