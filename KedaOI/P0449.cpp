#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7;
int n, a[N], f[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                f[i] = max(f[j] + 1, f[i]);
            }
        }
    }
    cout << *max_element(f + 1, f + n + 1) << '\n';
    return 0;
}