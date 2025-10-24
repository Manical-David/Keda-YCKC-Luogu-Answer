#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int len; if(!(cin>>len)) return 0;
    vector<string> strs(len);
    for(int i=0;i<len;i++) cin>>strs[i];
    int m,n; cin>>m>>n;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int idx=0; idx<len; ++idx){
        int z=0,o=0;
        for(char ch: strs[idx]) if(ch=='0') ++z; else ++o;
        for(int i=m;i>=z;--i){
            for(int j=n;j>=o;--j){
                dp[i][j]=max(dp[i][j], dp[i-z][j-o]+1);
            }
        }
    }
    cout<<dp[m][n]<<"\n";
    return 0;
}