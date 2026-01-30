#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int t = 0; t < t; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> tong(a.begin() + 1, a.end());
        sort(tong.begin(), tong.end(), greater<int>());
        int cnt = 0;
        int t_a_1 = a[0];
        for (int i = 0; i < tong.size(); ++i) {
            if (t_a_1 > tong[i]) {
                break;
            }
            int mid = tong[i] / 2;
            t_a_1 += mid;
            tong[i] -= mid;
            cnt++;
        }
        
        cout << cnt << '\n';
    }
    return 0;
}