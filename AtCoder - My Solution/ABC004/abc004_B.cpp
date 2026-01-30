#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    char c[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 3; i >= 0; i--) {
        for(int j = 3; j >= 0; j--) {
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}