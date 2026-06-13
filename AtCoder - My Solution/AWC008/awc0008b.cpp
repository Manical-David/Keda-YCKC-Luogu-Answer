#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    long long h, maxh;
    cin >> h;
    int visa = 1;
    maxh = h;
    for (int i = 1; i < n; i++) {
        cin >> h;
        if (h > maxh) {
            visa++;
            maxh = h;
        }
    }
    cout << visa << '\n';
    return 0;
}