#include <bits/stdc++.h>
using namespace std;
int solve(const string& str) {
    int N = str.length();
    for (int k = 1; k <= N; ++k) {
        if (N % k == 0) {
            bool flag = true;
            for (int i = 0; i < N; ++i) {
                if (str[i] != str[i % k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return k;
            }
        }
    }
    return N;
}
int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int ans = solve(s);
    cout << ans << endl;
    return 0;
}