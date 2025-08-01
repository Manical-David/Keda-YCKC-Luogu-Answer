#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    double n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < sqrt(n); i++) {
        for(int j = 0; j < sqrt(n); j++) {
            if(i * j == (int)n) ans++;
        }
    }
    cout << ans;
    return 0;
}