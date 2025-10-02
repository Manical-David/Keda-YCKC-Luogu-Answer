#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("flip.in", "r", stdin);
    freopen("flip.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> rz(n, 0);
    vector<int> cz(m, 0);
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '0') {
                rz[i]++;
                cz[j]++;
                zeros++;
            }
        }
    }
    if (zeros == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int minr = *min_element(rz.begin(), rz.end());
    int minc = *min_element(cz.begin(), cz.end());
    int minn = zeros * 4;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tot = (rz[i] + cz[j] - (a[i][j] == '0')) * 4;
            int tong = zeros - rz[i] - cz[j] + (a[i][j] == '0');
            tot += tong * 3;
            if (tot < minn) {
                minn = tot;
            }
        }
    }
    cout << minn << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
