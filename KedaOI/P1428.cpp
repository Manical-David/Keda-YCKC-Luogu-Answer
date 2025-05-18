#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1001;
int a[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, s;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    cout << a[s] << '\n';
    return 0;
}