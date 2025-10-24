#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int S, A, B, X;
    cin >> S >> A >> B >> X;
    int cntt = A + B;
    int cntd = S * A;
    int cnt = X / cntt;
    int tong = X % cntt;
    int dis = cnt * cntd + S * min(tong, A);
    cout << dis << endl;
    return 0;
}
