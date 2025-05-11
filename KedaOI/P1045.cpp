#include <bits/stdc++.h>
using namespace std;
bool containsDigit(int num, int t) {
    if(t == 0 && num == 0) return true;
    while(num > 0) {
        int digit = num % 10;
        if(digit == t) return true;
        num /= 10;
    }
    return false;// 没找到t
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int m, t;
    cin >> m >> t;
    int realFloor = 0;
    for(int i = 1; i <= m; i++) {
        if(!containsDigit(i, t)) {
            realFloor++;
        }
    }
    cout << realFloor << '\n';
    return 0;
}