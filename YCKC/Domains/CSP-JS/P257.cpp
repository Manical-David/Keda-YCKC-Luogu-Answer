#include <bits/stdc++.h>
using namespace std;
int a, b, n, ans, x[40] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000}, book[40];
void dfs(int km) {
    for (int i = 1; i <= n + 13; i++) {
        if (x[i] >= km + a && x[i] <= km + b && book[i] == 0) {
            if (x[i] == 7000) {
                ans++;
                return ;
            }
            book[i] = 1;
            dfs(x[i]);
            book[i] = 0;
        }
        else if (km + a >= 7000) {
            ans++;
            return ;
        }
    }
    return ;
}
int main() {
    cin >> a >> b >> n;
    for (int i = 13; i <= n + 12; i++)
        cin >> x[i];
    dfs(0);
    cout << ans;
    return 0;
}