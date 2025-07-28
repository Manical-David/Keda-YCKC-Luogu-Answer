#include <bits/stdc++.h>
using namespace std;
bool check(long long x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    long long N;
    cin >> N;
    long long ans = 1;
    long long max_x = pow(N, 1.0/3) + 2;
    for(long long x = max_x; x >= 1; --x) {
        long long cube = x * x * x;
        if(cube > N) continue;
        if(check(cube)) {
            ans = cube;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}