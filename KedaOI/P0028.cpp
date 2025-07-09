#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int tong;
    cin >> tong;
    for(int i = 1; i <= n;  i++) {
        if(a[i] == tong) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}