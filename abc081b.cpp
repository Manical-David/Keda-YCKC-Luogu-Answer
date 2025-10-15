#include <bits/stdc++.h>
using namespace std;
bool check(vector <int> &a) {
    for(int it : a) {
        if(it % 2 == 1) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    while(check(a)) {
        ans++;
        for(int &it : a) {
            it /= 2;
        }
    }
    cout << ans << '\n';
    return 0;
}