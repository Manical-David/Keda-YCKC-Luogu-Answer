#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b = 0;
    int c = 0;
    int d = INT_MAX;
    for (int i = 0; i < n; ++i) {
        c += a[i];
        while (c >= s) {
            d = min(d, i - b + 1);
            c -= a[b];
            b++;
        }
    }
    cout << (d != INT_MAX ? d : 0) << endl;
    return 0;
}