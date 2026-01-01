#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int ans = 0;
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                if (a * 500 + b * 100 + c * 50 == X) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}