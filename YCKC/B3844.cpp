#include <bits/stdc++.h>
using namespace std;
char givechar(char c, int n) {
    if((int)c + n <= 26) return char(c + n);
    else return char(c + n - 26);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << givechar(char('A' + i), j);
        }
        cout << '\n';
    }
    return 0;
}