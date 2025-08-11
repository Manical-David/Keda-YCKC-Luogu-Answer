#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 0;
    int dis = m;
    for (int i = 0; i < n; ++i) {
        if (dis <= 0) {
            break;
        }
        dis -= a[i];
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}
