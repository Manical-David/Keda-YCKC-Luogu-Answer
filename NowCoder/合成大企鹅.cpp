#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double T = 0.00;
    T = a[0];
    for (int i = 1; i < n; i++) {
        T = sqrt(T * a[i]);
    }
    cout << T;
    return 0;
}