#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int ts = N / 5;
    int num = N % 5;
    int ans;
    if (num <= 2) {
        ans = ts * 5;
    } 
    else {
        ans = (ts + 1) * 5;
    }
    cout << ans << '\n';
    return 0;
}