#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, k;
    cin >> n >> k;
    if(n % k == 0) {
        cout << n;
    }
    else cout << k % n;
    return 0;
}