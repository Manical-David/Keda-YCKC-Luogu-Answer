#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int a, b, minn = INT_MAX;
        cin >> a >> b;
        for(int i = a; i <= b; i++) {
            if(minn > (i - a) + (b - i)) minn = (i - a) + (b - i);
        }
        cout << minn << '\n';
    }
    return 0;
}