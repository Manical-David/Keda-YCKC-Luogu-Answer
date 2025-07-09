#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, D;
    cin >> N >> D;
    long long d = 2 * D + 1;
    long long ans = (N + d - 1) / d;
    cout << ans << endl;
    return 0;
}