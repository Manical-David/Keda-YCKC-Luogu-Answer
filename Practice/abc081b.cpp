#include <bits/stdc++.h>
using namespace std;
int gettern(int x) {
    if (x % 2 == 1) return 0;
    else return gettern(x / 2) + 1;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n, 0);
    int minn = -0x3f3f3f;
    for (int &it : a) {
        cin >> it;
    }
    minn = gettern(a[0]);
    for (int it : a) {
        minn = min(gettern(it), minn);
    }
    cout << minn << '\n';
    return 0;
}