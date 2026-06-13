#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    long long sum = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] > d[i-1]) {
            sum += d[i] / 2;
        } 
        else {
            sum += d[i];
        }
    }
    cout << sum << '\n';
    return 0;
}