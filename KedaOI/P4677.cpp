#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int dp[N][N];
int dfs(string str, int l, int r) {
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    int res = -1;
    if(l >= r) {
        res = 0;
    }
    else if(l + 1 == r) {
        res = str[l] == str[r] ? 0 : 1;
    }
    else {
        if(str[l] == str[r]) {
            res = dfs(str, l + 1, r - 1);
        }
        else {
            res = min(dfs(str, l + 1, r) + 1, dfs(str, l, r - 1) + 1);
        }
    }
    dp[l][r] = res;
    return res;
}
int solve(string str) {
    memset(dp, -1, sizeof(dp));
    int len = str.size();
    return dfs(str, 0, len - 1);
}
int main() {
    string str;
    cin >> str;
    cout << solve(str) << '\n';
    return 0;
}