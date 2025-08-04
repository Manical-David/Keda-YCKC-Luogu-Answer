#include <bits/stdc++.h>
using namespace std;
long long t = 0, n = 0, x = 0, pre[1919810] = {}, y = 0, sum = 0;
bool flag = 0;
char s;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            if (s == '1') pre[i] = pre[i - 1] - 1;
            else pre[i] = pre[i - 1] + 1;
            if (pre[i] == x) flag = 1;
        }
        if (pre[n] == 0) {
            if (flag == 0) cout << "0\n";
            else cout << "-1\n";
        }
        else {
            for (int i = 1; i <= n; i++) {
                y = (x - pre[i]) / pre[n];
                if (y >= 0 && y * pre[n] + pre[i] == x) sum++;
            }
            if (x == 0) sum++;
            cout << sum << "\n";
        }
        sum = 0;
        flag = 0;
    }
    return 0;
}