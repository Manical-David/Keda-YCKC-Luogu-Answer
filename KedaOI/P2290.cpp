#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int a, ans_1, ans_2;
    cin >> a;
    ans_1 = a / 13;
    ans_2 = a - ans_1 * 13;
    cout << ans_1 << "\n" << ans_2 << endl;
    return 0;
}