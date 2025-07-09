#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int a[N];
int main() {
    int n;
    long long tong = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i];
    }
    tong /= n;
    for(int i = 0; i < n; i++) {
        if(a[i] > tong) ans++;
    }
    cout << ans;
    return 0;
}