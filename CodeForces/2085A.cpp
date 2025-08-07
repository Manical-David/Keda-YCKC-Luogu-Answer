#include <bits/stdc++.h>
using namespace std;
void solve() {
    long n, k; 
    cin >> n >> k;
    string s; cin >> s;
    string t(s); 
    reverse(t.begin(),t.end());
    bool res = s < t;
    bool diff = false;
    for(size_t p = 1; !res && k && !diff && p < s.size(); p++) {
        if(s[p - 1] != s[p]) diff = true;
    }
    if(k && diff) res = true;
    cout << (res ? "YES\n" : "NO\n");
}
int main(){
    long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}