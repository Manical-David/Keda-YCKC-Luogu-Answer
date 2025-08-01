#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int t;
    cin >> t;
    bool flag = false;
    while(t--) {
        flag = false;
        int n;
        cin >> n;
        vector <int> a(n + 1), sum(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for(int i = 1; i <= n; i++) {
            if(sum[i] == (sum[n] - sum[i])) {
                cout << "Yes\n";
                flag = true;
            }
        }
        if(!flag) cout << "No\n";
    }
    return 0;
}