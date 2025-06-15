#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1001;
int a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(a[i] + a[j] == 0) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}