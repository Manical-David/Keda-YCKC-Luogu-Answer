#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cnt++;
        }
    }
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = (a[i] == 0) ? 1 : -1;
    }
    // Kadane
    int Max = d[0];
    int Mgl = d[0];
    for (int i = 1; i < n; ++i) {
        Max = max(d[i], Max + d[i]);
        Mgl = max(Mgl, Max);
    }
    int res = cnt + Mgl;
    cout << res << endl;
    return 0;
}
