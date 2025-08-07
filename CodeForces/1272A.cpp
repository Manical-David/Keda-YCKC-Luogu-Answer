#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    vector <int> x(3);
    cin >> x[0] >> x[1] >> x[2];
    sort(x.begin(), x.end());
    if(x[0] < x[2]) x[0]++;
    if(x[1] < x[2]) x[1]++;
    if(x[2] > x[0]) x[2]--;
    int ans = 2 * (x[2] - x[0]);
    cout << ans << '\n';
}
signed main(){
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}