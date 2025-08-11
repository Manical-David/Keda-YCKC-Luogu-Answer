#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main() {
    LL m;
    cin >> m;
    LL l = 1;
    LL r = 2;
    LL sum = 3;
    while(l <= m / 2 && r <= m && l < r) {
        if(sum == m) {
            cout << l << ' ' << r << '\n';
            sum -= l;
            l++;
        }
        else if(sum < m) {
            r++;
            sum += r;
        }
        else {
            sum -= l;
            l++;
        }
    }
    return 0;
}