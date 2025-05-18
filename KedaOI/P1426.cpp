#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(i % 2 == 1) {
            cout << i << " ";
        }
    }
    return 0;
}