#include <bits/stdc++.h>
using namespace std;
long long solve(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long prvv = 1; 
    long long ans = 1;
    long long cur;
    for (int i = 2; i <= n; ++i) {
        cur = ans + prvv;
        prvv = ans;
        ans = cur;
    }
    
    return ans;
}
int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;
    return 0;
}