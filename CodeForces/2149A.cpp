#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    int c = 0, k = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i]==0){
            c++;
        }
        if(a[i]==-1){
            k++;
        }
    }
    if(k%2==1){
        c+=2;
    }
    cout<<c<<endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}