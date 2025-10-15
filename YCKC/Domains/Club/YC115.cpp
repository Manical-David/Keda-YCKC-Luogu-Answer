#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int ans = 0;
    for(int i = 0; i <= 1000; i++){
        ans += i;
    }
    cout << ans;
    return 0;
}