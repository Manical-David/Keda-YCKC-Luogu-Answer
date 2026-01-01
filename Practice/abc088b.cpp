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
    int bob = 0, alice = 0;
    bool bobturn = false, aliceturn = true;
    for (int i = 0; i < a.size(); i++) {
        if (bobturn) {
            bob += a[i];
            bobturn = false;
            aliceturn = true;
        }
        else if (aliceturn) {
            alice += a[i];
            bobturn = true;
            aliceturn = false;
        }
    }
    cout << abs(alice - bob);
    return 0;
}