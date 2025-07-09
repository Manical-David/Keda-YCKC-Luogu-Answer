#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = ans + a[i];
    }
    cout << ans;
    return 0;
}