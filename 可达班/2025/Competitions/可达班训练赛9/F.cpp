#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int gcdd = a[i];
        int xorr = a[i];
        for (int j = i + 1; j < n; ++j) {
            gcdd = gcd(gcdd, a[j]);
            xorr ^= a[j];
            if (gcdd == xorr) {
                cnt++;
            }
            if (gcdd == 1 && xorr > 1) {
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
