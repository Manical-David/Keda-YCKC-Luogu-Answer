#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;
int a[15];
bool check(int row) {
    for (int i = 1; i < row; i++) {
        if (a[i] == a[row] || abs(a[i] - a[row]) == row - i) {
            return false;
        }
    }
    return true;
}
void solve(int row) {
    if (row == n + 1) {
        sum++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[row] = i;
        if (check(row)) {
            solve(row + 1);
        }
    }
}
int main() {
    cin >> n;
    solve(1);
    cout << sum << endl;
    return 0;
}